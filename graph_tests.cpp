#include <stdlib.h>

#include "graph_tests.h"

Graph createGraph(int V, int E)
{
    Graph g = new graph;
    g->num_nodes = V;
    g->num_edges = E;
    g->offsets = new int[V];
    g->edges = new Vertex[E];
    g->weights = new int[E];
    return g;
}

Graph createSimpleGraph() {
    int V = 4;  // Number of vertices in graph
    int E = 10;  // Number of edges in graph
    
    Graph g = createGraph(V, E);
    int offsets[4] = {0,2,5,7};
    for(int i = 0; i < V; i++){
        g->offsets[i] = offsets[i];
    }
    int edges[10] = {1,3,0,2,3,1,3,0,1,2};
    int weights[10] = {2,6,2,3,4,3,1,6,4,1};
    for(int i = 0; i < E; i++){
        g->edges[i] = edges[i];
        g->weights[i] = weights[i];
    }
    
    return g;
}
