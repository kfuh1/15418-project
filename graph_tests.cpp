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

Graph createStarGraph() {
    int V = 6;  // Number of vertices in graph
    int E = 10;  // Number of edges in graph
    
    Graph g = createGraph(V, E);
    int offsets[6] = {0,1,2,3,4,5};
    for(int i = 0; i < V; i++){
        g->offsets[i] = offsets[i];
    }
    int edges[10] = {5,5,5,5,5,0,1,2,3,4};
    int weights[10] = {3,2,2,10,11,3,2,2,10,11};
    for(int i = 0; i < E; i++){
        g->edges[i] = edges[i];
        g->weights[i] = weights[i];
    }
    
    return g;
}

Graph createCycleGraph() {
    int V = 7;  // Number of vertices in graph
    int E = 14;  // Number of edges in graph
    
    Graph g = createGraph(V, E);
    int offsets[7] = {0,2,4,6,8,10,12};
    for(int i = 0; i < V; i++){
        g->offsets[i] = offsets[i];
    }
    int edges[14] = {1,6,0,2,1,3,2,4,3,5,4,6,0,5};
    int weights[14] = {5,1,5,1,1,2,2,3,3,10,10,6,6,1};
    for(int i = 0; i < E; i++){
        g->edges[i] = edges[i];
        g->weights[i] = weights[i];
    }
    
    return g;
}

Graph createLineGraph() {
    int V = 4;  // Number of vertices in graph
    int E = 6;  // Number of edges in graph
    
    Graph g = createGraph(V, E);
    int offsets[4] = {0,1,3,5};
    for(int i = 0; i < V; i++){
        g->offsets[i] = offsets[i];
    }
    int edges[6] = {1,0,2,1,3,2};
    int weights[6] = {5,5,4,4,7,7};
    for(int i = 0; i < E; i++){
        g->edges[i] = edges[i];
        g->weights[i] = weights[i];
    }
    
    return g;
}

Graph createCrazyGraph() {
    int V = 12;  // Number of vertices in graph
    int E = 26;  // Number of edges in graph
    
    Graph g = createGraph(V, E);
    int offsets[12] = {0,1,5,7,8,12,16,17,22,23,24,25};
    for(int i = 0; i < V; i++){
        g->offsets[i] = offsets[i];
    }
    int edges[26] = {1,0,2,4,5,1,5,4,1,3,5,7,1,2,4,6,5,4,8,9,10,11,7,7,7,7};
    int weights[26] = {5,5,4,10,3,4,11,2,10,2,2,3,11,2,1,2,1,2,6,6,7,3,6,6,7,3};
    for(int i = 0; i < E; i++){
        g->edges[i] = edges[i];
        g->weights[i] = weights[i];
    }
    
    return g;
}

Graph createGeeksGraph(){
    int V = 9;
    int E = 28;

    Graph g = createGraph(V, E);
    int offsets[9] = {0,2,5,9,12,14,18,21,25};
    for(int i = 0; i < V; i++){
        g->offsets[i] = offsets[i];
    }
    int edges[28] = {1,7,0,2,7,1,3,5,8,2,4,5,3,5,2,3,4,6,5,7,8,0,1,6,8,2,6,7};
    int weights[28] = {4,8,4,8,11,8,7,4,2,7,9,14,9,10,4,14,10,2,2,1,6,8,11,1,7,2,6,7};
    for(int i = 0; i < E; i++){
        g->edges[i] = edges[i];
        g->weights[i] = weights[i];
    }
    
    return g;
}

Graph create7CycleGraph(){
    int V = 7;
    int E = 14;

    Graph g = createGraph(V,E);
    int offsets[7] = {0,2,4,6,8,10,12};
    
    for(int i = 0; i < V; i++){
        g->offsets[i] = offsets[i];
    }
    int edges[14] = {1,6,0,2,1,3,2,4,3,5,4,6,0,5};
    int weights[14] = {4,5,4,3,3,6,6,4,4,3,3,2,2,5};
    for(int i = 0; i < E; i++){
        g->edges[i] = edges[i];
        g->weights[i] = weights[i];
    }
    
    return g;
}
