#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

#include "boruvka_parallel.h"
#include "union_find.h"

void find_MST_parallel(Graph g){
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
    int prev_num_components;
    #pragma omp parallel for schedule(static)
    for(int i = 0; i < n; i++){
        components[i].parent = i;
        components[i].rank = 0;
        is_first_passes[i] = true;
    }

    //continue looping until there's only 1 component
    //in the case of a disconnected graph, until num_components doesn't change
    while(num_components > 1 && prev_num_components != num_components){
        prev_num_components = num_components;
        //find minimum weight edge out of each componenet
        #pragma omp parallel for schedule(dynamic, 256)
        for(int i = 0; i < n; i++){
            const Vertex* start = edges_begin(g, i);
            const Vertex* end = edges_end(g, i);
            int weight_offset = -1;
            for(const Vertex* v = start; v < end; v++){
                weight_offset++;
                //get representative nodes 
                int set1 = find_parallel(components, i);
                int set2 = find_parallel(components, *v);
                //this edge has already been contracted (endpoints in same component)
                if(set1 != set2){
                    Edge e;
                    e.src = i;
                    e.dest = *v;
                    e.weight = g->weights[g->offsets[i] + weight_offset];
                    #pragma omp critical
                    {
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
        }
        #pragma omp barrier
        //contract based on min edges found
        #pragma omp parallel for schedule(dynamic, 256)
        for(int i = 0; i < n; i++){
            int src = min_edges[i].src;
            int dest = min_edges[i].dest;

            int root1 = find_parallel(components, src);
            int root2 = find_parallel(components, dest);
            if(root1 == root2){
                continue;
            }
            union_parallel(components, root1, root2);
            //for edges found, add to mst
            #pragma omp critical
            {
            //add the edge in the index of smaller value
            //since we're always unioning onto larger node
                mst_edges[mst_edges_idx] = min_edges[i];
                mst_edges_idx += 1;
                num_components--;
            }
            
        }

        #pragma omp parallel for schedule(static)
        for(int i = 0; i < n; i++){
            is_first_passes[i] = true;
        }
        #pragma omp barrier 
    }

    for(int i = 0; i < n-1; i++){
        printf("%d,%d\n", mst_edges[i].src, mst_edges[i].dest);
    }
    
    delete[] min_edges;
    delete[] components;
}
