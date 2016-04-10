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
void insert(Graph g, int vertex, Edge newEdge){
    ListNode node = g->adjList[vertex];
    ListNode newNode = new struct list_node;
    newNode->e = newEdge;
    newNode->next = NULL;

    if(node == NULL){
        node = newNode;
        g->adjList[vertex] = node;
        /**printf("First added edge\n");
        while(node != NULL) {
          printf("Src:%d, Dest:%d\n", node->e.src, node->e.dest);
          node = node->next;
        }**/
        return;
    }
    ListNode ptr = node;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    g->adjList[vertex] = node;
    
    /**printf("Not the first edge\n");
    while(node != NULL) {
      printf("Src:%d, Dest:%d\n", node->e.src, node->e.dest);
      node = node->next;
    }**/
}

//graph functions
int get_num_nodes(Graph g){
    return g->num_nodes;
}

int get_num_edges(Graph g){
    return g->num_edges;
}
#endif
