#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "boruvka_sequential.h"
#include "graph.h"
#include "union_find.h"

Graph createGraph(int V, int E)
{
    Graph g = new graph;
    g->num_nodes = V;
    g->num_edges = E;
    g->adjList = new ListNode[2*E];
    return g;
}

int main(int argc, char** argv){
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    
    Graph g = createGraph(V, E);
            
    // add edge 0-1
    struct Edge e0;
    e0.src = 0;
    e0.dest = 1;
    e0.weight = 10;
    insert(&(g->adjList[e0.src]), e0);
    struct Edge e0_rev;
    e0_rev.src = 1;
    e0_rev.dest = 0;
    e0_rev.weight = 10;
    insert(&(g->adjList[e0_rev.src]), e0_rev);
    
    // add edge 0-2
    struct Edge e1;
    e1.src = 0;
    e1.dest = 2;
    e1.weight = 6;
    insert(&(g->adjList[e1.src]), e1);
    struct Edge e1_rev;
    e1_rev.src = 2;
    e1_rev.dest = 0;
    e1_rev.weight = 6;
    insert(&(g->adjList[e1_rev.src]), e1_rev);
                                  
    // add edge 0-3
    struct Edge e2;
    e2.src = 0;
    e2.dest = 3;
    e2.weight = 5;
    insert(&(g->adjList[e2.src]), e2);
    struct Edge e2_rev;
    e2_rev.src = 3;
    e2_rev.dest = 0;
    e2_rev.weight = 5;
    insert(&(g->adjList[e2_rev.src]), e2_rev);
                                                    
    // add edge 1-3
    struct Edge e3;
    e3.src = 1;
    e3.dest = 3;
    e3.weight = 15;
    insert(&(g->adjList[e3.src]), e3);
    struct Edge e3_rev;
    e3_rev.src = 3;
    e3_rev.dest = 1;
    e3_rev.weight = 15;
    insert(&(g->adjList[e3_rev.src]), e3_rev);
     
    // add edge 2-3
    struct Edge e4;
    e4.src = 2;
    e4.dest = 3;
    e4.weight = 4;
    insert(&(g->adjList[e4.src]), e4);
    struct Edge e4_rev;
    e4_rev.src = 3;
    e4_rev.dest = 2;
    e4_rev.weight = 4;
    insert(&(g->adjList[e4_rev.src]), e4_rev);
    
    /*for (int i = 0; i < V; i++) {
       ListNode edgeNode = g->adjList[i];
       printf("Vertex %d\n", i);
       while(edgeNode != NULL) {
        printf("Dest: %d\n", edgeNode->e.dest);
        edgeNode = edgeNode->next;
       }
    }*/

    find_MST(g);
                                                                              
    return 0;
}
