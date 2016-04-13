#include "graph.h"

//linked list functions
void insert(ListNode* node, Edge newEdge){
    ListNode newNode = new struct list_node;
    newNode->e = newEdge;
    newNode->next = NULL;

    if(node == NULL){
        return;
    }
    if(*node == NULL){
        *node = newNode;
        return;
    }
    ListNode ptr = *node;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    
}

//graph functions
int get_num_nodes(Graph g){
    return g->num_nodes;
}

int get_num_edges(Graph g){
    return g->num_edges;
}
