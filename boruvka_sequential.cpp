#include <stdlib.h>
#include <stdio.h>
#include <climits>

#include "graph.h"
#include "union_find.h"

#define MAX_WEIGHT INT_MAX

//modifies the graph g directly instead of returning something
void find_MST(Graph g){
    int n = get_num_nodes(g);
    int m = get_num_edges(g);
    
    //store the edge index of the min weight edge incident on node i
    int min_edges[n];
    struct set components[n];
    union_sets(components, 1, 2); 
    int num_components = n;
    
    //initialize min_edges array
    for(int i = 0; i < n; i++){
        components[i].parent = i;
        components[i].rank = 0;
        min_edges[i] = -1;
    }

    while(num_components > 1){
        //go through all the edges and find the min weight edge on each vertex
        for(int i = 0; i < m; i++){
        }
    }
}
