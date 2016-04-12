#ifndef __BORUVKA_H__
#define __BORUVKA_H___

#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "union_find.h"

void find_MST(Graph g){
    int n = get_num_nodes(g);
    //store the edge index of the min weight edge incident on node i
    struct Edge* min_edges = new struct Edge[n];
    struct set *components = new struct set[n];
    int num_components = n;
   
    /*Edge emptyEdge;
    emptyEdge.src = -1;
    emptyEdge.dest = -1;
    emptyEdge.weight = -1; */
    //initialize min_edges array
    for(int i = 0; i < n; i++){
        components[i].parent = i;
        components[i].rank = 0;
        //min_edges[i] = emptyEdge;
    }

    while(num_components > 1){
        //find minimum weight edge out of each componenet
        for(int i = 0; i < n; i++){
            ListNode edgeNode = g->adjList[i];
            bool isFirstPass = true;
            //int curr_min_weight = 0;
            while(edgeNode != NULL){
        //        printf("hello");
                //get representative nodes
                int set1 = find(components, i);
                int set2 = find(components, edgeNode->e.dest);
                //this edge has already been contracted (endpoints in same component)
                if(set1 != set2){
                    if(isFirstPass){
                        min_edges[set1] = edgeNode->e; 
                        isFirstPass = false;
                    }
                    else if (min_edges[set1].weight > edgeNode->e.weight)
                        min_edges[set1] = edgeNode->e;
                }
                edgeNode = edgeNode->next;
            }
        }
        //contract based on min edges found
        for(int i = 0; i < n; i++){
            int dest = min_edges[i].dest;
            int root1 = find(components, i);
            int root2 = find(components, dest);
            if(root1 == root2){
                continue;
            }
            union_sets(components, i, dest);
            num_components--;
        }
        
    }
   
    /*for(int i = 0; i < n; i++) {
      if(min_edges[min_edges[i]] == i) {
        min_edges[i] = -1;
      }
    }*/

    for(int i = 0; i < n; i++){
      if (min_edges[i].src != -1)
        printf("src %d to dest %d\n", i, min_edges[i].dest);
    }
}
#endif
