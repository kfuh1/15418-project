#ifndef __BORUVKA_H__
#define __BORUVKA_H___

#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "union_find.h"

void find_MST(Graph g){
    int n = get_num_nodes(g);
    //store the edge index of the min weight edge incident on node i
    int min_edges[n];
    struct set *components = new struct set[n];
    int num_components = n;
    
    //initialize min_edges array
    for(int i = 0; i < n; i++){
        components[i].parent = i;
        components[i].rank = 0;
        min_edges[i] = -1;
    }

    while(num_components > 1){
        //find minimum weight edge out of each componenet
        for(int i = 0; i < n; i++){
            ListNode edgeNode = g->adjList[i];
            int curr_min_weight = 0;
            while(edgeNode != NULL){
                if(min_edges[i] == -1){
                    min_edges[i] = edgeNode->e.dest;
                    curr_min_weight = edgeNode->e.weight;
                }
                else{
                    if(edgeNode->e.weight < curr_min_weight){
                        min_edges[i] = edgeNode->e.dest;
                        curr_min_weight = edgeNode->e.weight;
                    }
                }
                edgeNode = edgeNode->next;
            }
        }
        //contract based on min edges found
        for(int i = 0; i < n; i++){
            int dest = min_edges[i];
            int root1 = find(components, i);
            int root2 = find(components, dest);
            if(root1 == root2){
                continue;
            }
            union_sets(components, i, dest);
            num_components--;
        }
    }
   
    for(int i = 0; i < n; i++) {
      if(min_edges[min_edges[i]] == i) {
        min_edges[i] = -1;
      }
    }

    for(int i = 0; i < n; i++){
      if (min_edges[i] != -1)
        printf("src %d to dest %d\n", i, min_edges[i]);
    }
}
#endif
