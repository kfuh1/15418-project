#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef int Vertex;
struct Edge {
    Vertex src;
    Vertex dest;
    int weight;
};
typedef struct Edge Edge;

struct ListNode {
    Edge e;
    ListNode* next;
};
typedef struct ListNode ListNode;

typedef struct graph* Graph;

/* Getters */
static inline int num_nodes(const Graph);
static inline int num_edges(const Graph);


/* IO  - I'm not sure where these are defined or if we need them */
Graph load_graph(const char* filename);
Graph load_graph_binary(const char* filename);
void store_graph_binary(const char* filename, Graph);

void print_graph(const Graph);


/* Deallocation */
void free_graph(Graph);


/* Included here to enable inlining. Don't look. */
#include "graph_internal.h"

#endif
