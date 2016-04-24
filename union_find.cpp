#include <stdlib.h>

#include "union_find.h"

int find_seq(struct set *sets, int vertex){
    if(sets[vertex].parent != vertex)
        sets[vertex].parent = find_seq(sets, sets[vertex].parent);
    return sets[vertex].parent;
}

void union_seq(struct set *sets, int v1, int v2){
    int root1 = find_seq(sets, v1);
    int root2 = find_seq(sets, v2);

    int rank1 = sets[root1].rank;
    int rank2 = sets[root2].rank;
    
    if(rank1 < rank2){
        sets[root1].parent = root2;
    }
    else if(rank1 > rank2){
        sets[root2].parent = root1;
    }
    //decision to add to the root1 subset was arbitrary
    else{
        sets[root1].parent = root2;
        sets[root2].rank++;
    }
}

bool link_parallel(struct set *sets, int x, int y){
    if(x < y){
        return __sync_bool_compare_and_swap(&sets[x].parent, x, y);
    }
    else{
        return __sync_bool_compare_and_swap(&sets[y].parent, y, x); 
    }
}
int find_parallel(struct set *sets, int vertex){
    int parent = sets[vertex].parent;
    if(vertex != parent){
        int newp = find_parallel(sets, parent);
        __sync_bool_compare_and_swap(&sets[vertex].parent, parent, newp);
        return newp;
    }
    else{
        return vertex;
    }
}  

void union_parallel(struct set *sets, int x, int y){
    while(!link_parallel(sets, x,y)){
        while(x != sets[x].parent || y != sets[y].parent){
            x = find_parallel(sets, x);
            y = find_parallel(sets, y);
            if(x == y){
                return;
            }
        }
    }
}
