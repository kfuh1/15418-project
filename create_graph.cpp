#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "graph.h"
using namespace std;

Graph instantiate_graph(int V, int E){
    Graph g = new graph;
    g->num_nodes = V;
    g->num_edges = E;
    g->offsets = new int[V];
    g->edges = new Vertex[E];
    g->weights = new int[E];
    return g;
}

Graph create_graph(char *filename){
    char *file = filename;

    char *line_arr = new char[100];
    string line;
    ifstream myfile (file);

    int V, E;
    getline(myfile, line);
    strcpy(line_arr, line.c_str());
    char *graph_dims = strtok(line_arr, " ");
    V = atoi(graph_dims);
    graph_dims = strtok(NULL, " ");
    E = atoi(graph_dims);

    Graph g = instantiate_graph(V, 2 * E);

    int offset_count = 0;
    g->offsets[0] = offset_count;
    Vertex prev_vertex = 0;

    while(getline (myfile, line)){
        strcpy(line_arr, line.c_str());
        char* s = strtok(line_arr, " ");
        Vertex src = atoi(s);
        s = strtok(NULL, " ");
        Vertex dest = atoi(s);
        s = strtok(NULL, " ");
        int weight = atoi(s);
        if(src != prev_vertex){
            g->offsets[src] = offset_count;
            prev_vertex = src;
        }
        g->weights[offset_count] = weight;
        g->edges[offset_count] = dest;
        offset_count++;
    }
    myfile.close();
    /*for(int i = 0; i < V; i++){
        if(i == V-1){
            for(int k = g->offsets[i]; k < 2 * E; k++){
                printf("src %d to dest %d\n", i, g->edges[k]);
            }
            continue;
        }
        for(int j = g->offsets[i]; j < g->offsets[i+1]; j++){
            printf("src %d to dest %d\n", i, g->edges[j]);
        }
    }*/
    return g;
}
