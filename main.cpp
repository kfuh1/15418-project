#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "boruvka_sequential.h"
#include "boruvka_parallel.h"
#include "boruvka_parallel_star.h"
#include "boruvka_parallel_edge.h"
#include "boruvka_parallel_star2.h"
#include "graph.h"
#include "union_find.h"
#include "graph_tests.h"
#include "create_graph.h"

#include "CycleTimer.h"

int main(int argc, char** argv){
    //parse args to just get filename
    char* filename = argv[1];

    Graph graph = create_graph(filename);
    int n = graph->num_nodes;
    struct Edge* mst_seq;
    struct Edge* mst_par;    
    //sequential
    double startTimeSeq = CycleTimer::currentSeconds();
    mst_seq = find_MST(graph); 
    double endTimeSeq = CycleTimer::currentSeconds();
    printf("Total time sequential: %.20f\n", endTimeSeq - startTimeSeq);

    for(int i = 0; i < n; i++){
        if(mst_seq[i].src == 0 && mst_seq[i].dest == 0)
            continue;
        if(mst_seq[i].src < 0 || mst_seq[i].src > n || mst_seq[i].dest < 0 || mst_seq[i].dest > n)
            continue;
        printf("%d, %d\n", mst_seq[i].src, mst_seq[i].dest);
    }

    //parallel find by component with edge contraction
    double startTimePar = CycleTimer::currentSeconds();
    mst_par = find_MST_parallel(graph);
    double endTimePar = CycleTimer::currentSeconds();
    printf("Total time parallel: %.20f\n", endTimePar - startTimePar);

    //remember that the "Edge" in the name refers to finding by edges

    //parallel find by edge with edge contraction
/*    double startTimeParEdge = CycleTimer::currentSeconds();
    mst_par = find_MST_parallel_edge(graph);
    double endTimeParEdge = CycleTimer::currentSeconds();
    printf("Total time parallel find by edge: %.20f\n", endTimeParEdge - startTimeParEdge);
*/
    //parallel find by component with star contraction
   /* double startTimeStar = CycleTimer::currentSeconds();
    mst_par = find_MST_parallel_star(graph);
    double endTimeStar = CycleTimer::currentSeconds();
    printf("Total time parallel star: %.20f\n", endTimeStar - startTimeStar);
    */
    //parallel find by edge with star contraction
/*
    double startTimeStar2 = CycleTimer::currentSeconds();
    mst_par = find_MST_parallel_star2(graph);
    double endTimeStar2 = CycleTimer::currentSeconds();
    printf("Total time parallel star with edge find: %.20f\n", endTimeStar2 - startTimeStar2);
*/
    for(int i = 0; i < n; i++){
        if(mst_par[i].src == 0 && mst_par[i].dest == 0)
            continue;
        if(mst_par[i].src < 0 || mst_par[i].src > n || mst_par[i].dest < 0 || mst_par[i].dest > n)
            continue;
        printf("%d, %d\n", mst_par[i].src, mst_par[i].dest);
    }
  
    return 0;
}
