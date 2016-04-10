#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "boruvka.h"

Graph createGraph(int V, int E)
{
    Graph g = new graph;
    g->num_nodes = V;
    g->num_edges = E;
    return g;
}

int main(int argc, char** argv){
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    Graph g = createGraph(V, E);
             
             
    // add edge 0-1
    struct Edge e0;
    e0.src = 0;
    e0.dest = 1;
    e0.weight = 10;
    insert(g->adjList[e0.src], e0);
    insert(g->adjList[e0.dest], e0);
               
    // add edge 0-2
    struct Edge e1;
    e1.src = 0;
    e1.dest = 2;
    e1.weight = 6;
    insert(g->adjList[e1.src], e1);
    insert(g->adjList[e1.dest], e1);
                                  
    // add edge 0-3
    struct Edge e2;
    e2.src = 0;
    e2.dest = 3;
    e2.weight = 5;
    insert(g->adjList[e2.src], e2);
    insert(g->adjList[e2.dest], e2);
                                                    
    // add edge 1-3
    struct Edge e3;
    e3.src = 1;
    e3.dest = 3;
    e3.weight = 15;
    insert(g->adjList[e3.src], e3);
    insert(g->adjList[e3.dest], e3);
                                                                     
    // add edge 2-3
    struct Edge e4;
    e4.src = 2;
    e4.dest = 3;
    e4.weight = 4;
    insert(g->adjList[e4.src], e4);
    insert(g->adjList[e4.dest], e4);
                                                                                      
    find_MST(g);
                                                                                           
    return 0;
}
