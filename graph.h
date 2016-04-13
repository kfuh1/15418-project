#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdlib.h>
#include <stdio.h>

typedef int Vertex;

struct Edge {
    Vertex src;
    Vertex dest;
    int weight;
};

struct list_node {
    struct Edge e;
    list_node* next;
};
typedef struct list_node* ListNode;

struct graph {
    int num_nodes;
    int num_edges;

    ListNode* adjList;
};
typedef graph* Graph;

//linked list functions
void insert(ListNode* node, Edge newEdge);

//graph functions
int get_num_nodes(Graph g);

int get_num_edges(Graph g);
#endif
