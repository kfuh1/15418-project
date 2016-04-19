#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "graph.h"

#define GRAPH_HEADER_TOKEN ((int) 0xDEADBEEF)

Graph load_graph_binary(const char* filename){
    Graph graph = (Graph)(malloc(sizeof(struct graph)));

    FILE* input = fopen(filename, "rb");

    if(!input){
        fprintf(stderr, "Could not open: %s\n", filename);
        exit(1);
    }
    int header[3];

    if(fread(header, sizeof(int), 3, input) != 3) {
        fprintf(stderr, "Error reading header.\n");
        exit(1);
    }
    if(header[0] != GRAPH_HEADER_TOKEN){
        fprintf(stderr, "Invalid graph file header. File may be corrupt.\n");
        exit(1);
    }
    graph->num_nodes = header[1];
    graph->num_edges = header[2];

    graph->offsets = (int*)malloc(sizeof(int) * graph->num_nodes);
    graph->edges = (int*)malloc(sizeof(int) * graph->num_edges);
    graph->weights = (int*)malloc(sizeof(int) * graph->num_edges);

    if (fread(graph->offsets, sizeof(int), graph->num_nodes, input) != (size_t) graph->num_nodes) {
        fprintf(stderr, "Error reading nodes.\n");
        exit(1);
    }

    if (fread(graph->edges, sizeof(int), graph->num_edges, input) != (size_t) graph->num_edges) {
        fprintf(stderr, "Error reading edges.\n");
        exit(1);
    }

    for(int i = 0; i < graph->num_edges; i++){
        graph->weights[i] = 1;
    }

    fclose(input);

    return graph;

}

void store_graph_binary(const char* filename, Graph graph) {

    FILE* output = fopen(filename, "wb");

    if (!output) {
        fprintf(stderr, "Could not open: %s\n", filename);
        exit(1);
    }

    int header[3];
    header[0] = GRAPH_HEADER_TOKEN;
    header[1] = graph->num_nodes;
    header[2] = graph->num_edges;

    if (fwrite(header, sizeof(int), 3, output) != 3) {
        fprintf(stderr, "Error writing header.\n");
        exit(1);
    }

    if (fwrite(graph->offsets, sizeof(int), graph->num_nodes, output) != (size_t) graph->num_nodes) {
        fprintf(stderr, "Error writing nodes.\n");
        exit(1);
    }

    if (fwrite(graph->edges, sizeof(int), graph->num_edges, output) != (size_t) graph->num_edges) {
        fprintf(stderr, "Error writing edges.\n");
        exit(1);
    }

    fclose(output);
}
void free_graph(Graph g){
    free(g->offsets);
    free(g->edges);
    free(g->weights);
    free(g);
}
