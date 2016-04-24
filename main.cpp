#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "boruvka_sequential.h"
#include "boruvka_parallel.h"
#include "graph.h"
#include "union_find.h"
#include "graph_tests.h"
#include "create_graph.h"

#include "CycleTimer.h"

int main(int argc, char** argv){
    //parse args to just get filename
    char* filename = argv[1];

    //Graph graph = load_graph_binary(filename); //using graph binaries assignment 3

    Graph graph = create_graph(filename);
    //printf("%d, %d\n", graph->num_nodes, graph->num_edges);
    //int weight_idx = 0; 
    /*for (int i = 0; i < graph->num_nodes; i++) {
        printf("src: %d\n", i);
        const Vertex* start = edges_begin(graph, i);
        const Vertex* end = edges_end(graph, i);
        for(const Vertex* v = start; v < end; v++){
            printf("dest: %d, weight: %d\n", *v, graph->weights[weight_idx]);
            weight_idx++;
        }  
    }*/

    double startTimeSeq = CycleTimer::currentSeconds();
    find_MST(graph); 
    double endTimeSeq = CycleTimer::currentSeconds();
    
    printf("Total time sequential: %.20f\n", endTimeSeq - startTimeSeq);
    /*int V = 12;  

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

    double startTimeSeq = CycleTimer::currentSeconds();

    find_MST(g);

    double endTimeSeq = CycleTimer::currentSeconds();

    double startTimePar = CycleTimer::currentSeconds();

    find_MST_parallel(g);

    double endTimePar = CycleTimer::currentSeconds();

    printf("Total time sequential: %.20f\n", endTimeSeq - startTimeSeq);
    printf("Total time parallel: %.20f\n", endTimePar - startTimePar);*/
    return 0;
}
