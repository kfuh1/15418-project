#ifndef __GRAPH_INTERNAL_H__
#define __GRAPH_INTERNAL_H__

#include <stdlib.h>
#include "contracts.h"

struct graph
{
    int num_edges;
    int num_nodes;
    ListNode* adjList;
};

int get_num_nodes(Graph g){
    return graph->num_nodes;
}

int get_num_edges(Graph g){
    return graph->num_edges;
}
#endif // __GRAPH_INTERNAL_H__
