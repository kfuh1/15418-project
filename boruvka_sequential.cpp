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

    struct Edge* mst_edges = new struct Edge[n-1];
    int mst_edges_idx = 0;
    //this is a hacky way to accommodate the fact that we look at every edge
    //even though we're contracting
    bool is_first_passes[n];

    for(int i = 0; i < n; i++){
        components[i].parent = i;
        components[i].rank = 0;
        is_first_passes[i] = true;
    }

    while(num_components > 1){
        //find minimum weight edge out of each componenet
        for(int i = 0; i < n; i++){
            const Vertex* start = edges_begin(g, i);
            const Vertex* end = edges_end(g, i);
            int weight_offset = -1;
            for(const Vertex* v = start; v < end; v++){
                weight_offset++;
                //get representative nodes
                
                int set1 = find(components, i);
                int set2 = find(components, *v);
                //this edge has already been contracted (endpoints in same component)
                if(set1 != set2){
                    Edge e;
                    e.src = i;
                    e.dest = *v;
                    e.weight = g->weights[g->offsets[i] + weight_offset];
                    if(is_first_passes[set1]){
                        min_edges[set1] = e; 
                        is_first_passes[i] = false;
                        is_first_passes[set1] = false;
                    }
                    else if (min_edges[set1].weight > e.weight)
                        min_edges[set1] = e;
                }
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
            //for edges found, add to mst
            mst_edges[mst_edges_idx] = min_edges[i];
            mst_edges_idx += 1;
            union_sets(components, i, dest);
            num_components--;
        }
        
        if(mst_edges_idx == n-1)
            break;

        for(int i = 0; i < n; i++){
            is_first_passes[i] = true;
        }
        
    }

    for(int i = 0; i < n-1; i++){
      //if (mst_edges[i].src != -1)
        printf("src %d to dest %d\n", mst_edges[i].src, mst_edges[i].dest);
    }
    delete[] min_edges;
    delete[] components;
}
