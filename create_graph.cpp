#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "graph.h"

Graph create_graph(int V, int seed) {
    srand(seed);
    int* offsets = new int[V];
    int* indices = new int[V];
    int* numEdges = new int[V];
    int E = 0;

    //initializing indices 
    for (int i = 0; i < V; i++) {
        indices[i] = 0;
    }
    
    offsets[0] = 0;
    for (int i = 1; i < V; i++) {
        int numE = (rand() % V) + 1;
        numEdges[i-1] = numE;
        offsets[i] = offsets[i - 1] + numE;
        E += numE;
    }
    numEdges[V-1] = E - offsets[V-1]; 
    
    int* weights = new int[E];
    int* edges = new int[E];

    for (int i = 0; i < V; i++) {
        int count = 0;
        int length = numEdges[i];
        while (count < length) {
            int dest = (rand() % V);
            int weight = (rand() % 100);
            if (indices[dest] >= numEdges[dest]) {
                continue; 
            }
            edges[offset[i] + indices[i]] = dest;
            weights[offset[i] + indices[i]] = weight;
            indices[i]++;
            weights[offset[dest] + indices[dest]] = weight;
            edges[offset[dest] + indices[dest]] = i;
            indices[dest]++;
            count++;
        }
    }
}

