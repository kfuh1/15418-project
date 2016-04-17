#include <omp.h>
#include "union_find.h"

int find(struct set *sets, int vertex){
    int parent = sets[vertex].parent;
    if(vertex != parent){
        sets[vertex].parent = find(sets, parent);
    }
    return parent;
}

void union_sets(struct set *sets, int v1, int v2){
    int root1 = find(sets, v1);
    int root2 = find(sets, v2);

    if(root1 == root2){
        return;
    }
    int rank1 = sets[root1].rank;
    int rank2 = sets[root2].rank;
    
    #pragma omp critical
    {
    if(rank1 < rank2){
        sets[root1].parent = root2;
    }
    else if(rank1 > rank2){
        sets[root2].parent = root1;
    }
    //decision to add to the root1 subset was arbitrary
    else{
        sets[root1].parent = root2;
        sets[root1].rank++;
    }
    }
}
