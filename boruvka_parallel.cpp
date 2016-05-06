#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

#include "boruvka_parallel.h"
#include "union_find.h"

#define THREADS 16
#define CHUNKSIZE 128
void find_MST_parallel(Graph g){
    omp_set_num_threads(THREADS);
    int n = get_num_nodes(g);
    //store the edge index of the min weight edge incident on node i
    struct Edge* min_edges = new struct Edge[n];
    struct set *components = new struct set[n];
    int num_components = n;

    bool can_be_contracted = true;
    //int *weights = new int[n];
    //int *dests = new int[n];


    //use this stuff so you can write into the temp_edges array in parallel
    //then sequentially loop through it and insert into the actual mst_edges
    //at least this way you can parallelize the find_parallel part 
    //struct Edge* temp_edges = new struct Edge[n-1];
    //Edge dummyEdge;
    //dummyEdge.src = -1;

    struct Edge* mst_edges = new struct Edge[n-1];
    int mst_edges_idx = 0;
    //this is a hacky way to accommodate the fact that we look at every edge
    //even though we're contracting
    bool is_first_passes[n];
    int prev_num_components = 0;
    #pragma omp parallel for schedule(static)
    for(int i = 0; i < n; i++){
        components[i].parent = i;
        components[i].rank = 0;
        is_first_passes[i] = true;
    }

    //continue looping until there's only 1 component
    //in the case of a disconnected graph, until num_components doesn't change
//    while(num_components > 1 && prev_num_components != num_components){
    while(can_be_contracted){
        prev_num_components = num_components;
        #pragma omp parallel for schedule(dynamic, CHUNKSIZE)
        for(int j = 0; j < n; j++){
            if(find_parallel(components, j) == j){
            //find minimum weight edge out of each componenet
                for(int i = 0; i < n; i++){
                    int set1 = find_parallel(components, i);
                    if(set1 == j){
                        const Vertex* start = edges_begin(g, i);
                        const Vertex* end = edges_end(g, i);
                        int weight_offset = -1;
                        for(const Vertex* v = start; v < end; v++){
                            weight_offset++;
                            //get representative nodes 
                            int set2 = find_parallel(components, *v);
                            //this edge has already been contracted (endpoints in same component)
                            if(set1 != set2){
                                Edge e;
                                e.src = i;
                                e.dest = *v;
                                e.weight = g->weights[g->offsets[i] + weight_offset];
                                if(is_first_passes[set1]){
                                    //weights[set1] = w;
                                    min_edges[set1] = e; 
                                    is_first_passes[set1] = false;
                                }
                                else if (min_edges[set1].weight > e.weight)
                                    min_edges[set1] = e;
                            }
                        }
                    }
                }
            }
        }
        can_be_contracted = false;
        //contract based on min edges found 
        //uses edge contraction which we couldn't think of a good way
        //to parallelize
        for(int i = 0; i < n; i++){
            int src = min_edges[i].src;
            int dest = min_edges[i].dest;

            int root1 = find_seq(components, src);
            int root2 = find_seq(components, dest);
            is_first_passes[i] = true;
            if(root1 == root2){
                continue;
            }
            can_be_contracted = true;
            union_seq(components, root1, root2);
            mst_edges[mst_edges_idx] = min_edges[i];
            mst_edges_idx += 1;
            //num_components--;
        }

    }

    /*for(int i = 0; i < n-1; i++){
        printf("%d,%d\n", mst_edges[i].src, mst_edges[i].dest);
    }*/
    delete[] min_edges;
    delete[] components;
}
