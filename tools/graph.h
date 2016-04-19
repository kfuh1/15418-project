#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdlib.h>

typedef int Vertex;

struct graph {
    int num_nodes;
    int num_edges;

    int* offsets;
    Vertex* edges;
    int* weights; 
};
typedef struct graph* Graph;

struct Edge {
    Vertex src;
    Vertex dest;
    int weight;
};

/* IO */
Graph load_graph_binary(const char* filename);
void store_graph_binary(const char* filename, Graph);

/* deallocation */
void free_graph(Graph);

//graph functions
static inline int get_num_nodes(const Graph g){
    return g->num_nodes;
}

static inline int get_num_edges(const Graph g){
    return g->num_edges;
}

static inline const Vertex* edges_begin(const Graph g, Vertex v){
    return g->edges + g->offsets[v];
}

static inline const Vertex* edges_end(const Graph g, Vertex v){
    int offset;
    if(v == g->num_nodes - 1)
        offset = g->num_edges;
    else
        offset = g->offsets[v + 1];
    return g->edges + offset;
}

static inline const int edge_list_size(const Graph g, Vertex v){
    if(v == g->num_nodes - 1)
        return g->num_edges - g->offsets[v];
    else
        return g->offsets[v + 1] - g->offsets[v];
    
}
#endif
