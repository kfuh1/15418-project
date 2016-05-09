#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

#include "boruvka_parallel_star.h"
#include "union_find.h"
#include "CycleTimer.h"

#define THREADS 8
#define CHUNKSIZE 128

void find_MST_parallel_star(Graph g){
    omp_set_num_threads(THREADS);
    int n = get_num_nodes(g);
    //store the edge index of the min weight edge incident on node i
    struct Edge* min_edges = new struct Edge[n];
    struct set *components = new struct set[n];

    struct Edge* mst_edges = new struct Edge[n];

    bool *coin_flips = new bool[n];
    //bool not_one_component = true;
    //keeps track of which tails have been contracted
    bool *is_contracted = new bool[n];
    
    //bool not_one_component = true;

    //this is a hacky way to accommodate the fact that we look at every edge
    //even though we're contracting
    bool is_first_passes[n];
    //loop guard - did the graph get smaller - only needs to be set by
    //at least one thread so it should work in the parallel version
    bool can_be_contracted = true;

    #pragma omp parallel for schedule(static)
    for(int i = 0; i < n; i++){
        components[i].parent = i;
        components[i].rank = 0;
        is_first_passes[i] = true;
    }

    double startTimeFind, endTimeFind;
    double findTotal = 0.0;
    double startTimeContract, endTimeContract;
    double contractTotal = 0.0;
    //continue looping until there's only 1 component
    //in the case of a disconnected graph, until num_components doesn't change
    //TODO is it better to have one condition here and not have to deal with
    //not_one_component (you would go one extra iteration but it could be worth 
    //it instad of having to loop through the components list every iteration -
    //but one iteration could be just as expensive so we'll have to see)
    while(can_be_contracted){
        startTimeFind = CycleTimer::currentSeconds();
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

        endTimeFind = CycleTimer::currentSeconds();
        findTotal += (endTimeFind - startTimeFind);

        startTimeContract = CycleTimer::currentSeconds();
        //TODO: need to rewrite union find so that it always contract the edge that we want
        //it to - this is necessary in star contraction so we contract into the HEAD        
        //determine which vertices will be star centers and which are satellites
        //we make 0 mean you are a satellite (false) and 1 mean you are a star center (true)
        #pragma omp parallel for schedule(static)
        for(int i = 0; i < n; i++){
            coin_flips[i] = ((rand() % 2) == 1);
        }

        //do this so we can see if any thread sets to true meaning something got contracted
        can_be_contracted = false;
        //star contraction - we'll say 1 is HEADS and 0 is TAILS
        #pragma omp parallel for schedule(dynamic, CHUNKSIZE) 
        for(int i = 0; i < n; i++){
            int src = min_edges[i].src;
            int dest = min_edges[i].dest;

            int root1 = find_parallel(components, src);
            int root2 = find_parallel(components, dest);
            if(root1 == root2){
                continue;
            }
            can_be_contracted = true;
            //you wouldn't contract in case of both heads or both tails
            if((coin_flips[root1] == coin_flips[root2])){
                continue;
            }
            //try to contract, but if you fail, that means someone has contracted already
            //I think this should be correct by how CAS works
            //mark the tail as having been contracted
            if(coin_flips[root1]){
                if(!__sync_bool_compare_and_swap(&is_contracted[root2],false,true))
                    continue;
            }
            else{
                if(!__sync_bool_compare_and_swap(&is_contracted[root1],false,true))
                    continue;
            }
            if(coin_flips[root1]){
                union_parallel(components, root2, root1);
                mst_edges[root2] = min_edges[i];
            }
            else{
                union_parallel(components, root1, root2);
                mst_edges[root1] = min_edges[i];
            }
        }

        #pragma omp parallel for schedule(static)
        for(int i = 0; i < n; i++){
            is_first_passes[i] = true;
            is_contracted[i] = false;
        }
        endTimeContract = CycleTimer::currentSeconds();
        contractTotal += (endTimeContract - startTimeContract);
/*        
        //update all the components - if we do this do we still need to
        //find in the first section
        #pragma omp parallel for schedule(static)
        for(int i = 0; i < n; i++){
            find_parallel(components, i);
        }
        //this logic is super confusing but i think it's correct
        //we want the loop to go while there are multiple components
        //(i.e. not_one_component = true)
        //here we check if any component is different from the first
        //if it differs then it fails the component check which means
        //we need to keep loping because we still have different components
        bool component_check = true;
        #pragma omp parallel for schedule(static)
        for(int i = 1; i < n; i++){
            if(components[i].parent != components[0].parent)
                component_check = false;
        }
        not_one_component = !component_check; */
        //TODO oh no, but now we've lost our ability to deal with non-connected things
        //because we don't have any way of checking prev_num_components to num_componens
        //maybe we can have a bool such as  did_contract because as long as you have
        //at least one contraction then you're good (but oh wait also, with star contraction there is non-zero
        //probability that you won't contract (if everyone flips tails)- how do we handle this, or do we actually
        //guarantee connected graphs now?)
    }

/*    for(int i = 0; i < n; i++){
        if(mst_edges[i].src == 0 && mst_edges[i].dest == 0)
            continue;
        if(mst_edges[i].src < 0 || mst_edges[i].src > n || mst_edges[i].dest < 0 || mst_edges[i].dest > n)
            continue;
        printf("%d, %d\n", mst_edges[i].src, mst_edges[i].dest);
    }
  */  
    printf("find time parallel comp star: %.20f\n", findTotal);
    printf("contract time parallel comp star: %.20f\n", contractTotal);
    delete[] min_edges;
    delete[] components;
}
