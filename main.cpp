#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "boruvka_sequential.h"
#include "graph.h"
#include "union_find.h"
#include "graph_tests.h"

Graph createGraph(int V, int E)
{
    Graph g = new graph;
    g->num_nodes = V;
    g->num_edges = E;
    g->offsets = new int[V];
    g->edges = new Vertex[2 * E];
    g->weights = new int[2 * E];
    return g;
}

int main(int argc, char** argv){
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    
    Graph g = createGraph(V, E);
            
    /*for (int i = 0; i < 7; i++) {
       ListNode edgeNode = g->adjList[i];
       printf("Vertex %d ", i);
       while(edgeNode != NULL) {
        printf("Dest: %d\n", edgeNode->e.dest);
        edgeNode = edgeNode->next;
       }
    }*/

    find_MST(g);
                                                                              
    return 0;
}
