#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "boruvka_sequential.h"
#include "graph.h"
#include "union_find.h"
#include "graph_tests.h"

#include "CycleTimer.h"

int main(int argc, char** argv){
    int V = 12;  

    //DEFINE GRAPH
    Graph g = createCrazyGraph();
    int weight_idx = 0;
    for (int i = 0; i < V; i++) {
        printf("src: %d\n", i);
        const Vertex* start = edges_begin(g, i);
        const Vertex* end = edges_end(g, i);
        for(const Vertex* v = start; v < end; v++){
            printf("dest: %d, weight: %d\n", *v, g->weights[weight_idx]);
            weight_idx++;
        }  
    }

    printf("-------------------------\n");

    double startTime = CycleTimer::currentSeconds();

    find_MST(g);

    double endTime = CycleTimer::currentSeconds();

    printf("Total time: %.20f\n", endTime - startTime);
                                                                            
    return 0;
}
