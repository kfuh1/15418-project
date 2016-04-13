#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "boruvka_sequential.h"
#include "graph.h"
#include "union_find.h"
#include "graph_tests.h"

/**Graph createGraph(int V, int E)
{
    Graph g = new graph;
    g->num_nodes = V;
    g->num_edges = E;
    g->adjList = new ListNode[2*E];
    return g;
}**/

int main(int argc, char** argv){
    //int V = 4;  // Number of vertices in graph
    //int E = 5;  // Number of edges in graph
    
    //Graph g = createGraph(V, E);
            
    // add edge 0-1
    /**struct Edge e0;
    e0.src = 0;
    e0.dest = 1;
    e0.weight = 4;
    insert(&(g->adjList[e0.src]), e0);
    struct Edge e0_rev;
    e0_rev.src = 1;
    e0_rev.dest = 0;
    e0_rev.weight = 4;
    insert(&(g->adjList[e0_rev.src]), e0_rev);
    
    // add edge 0-7
    struct Edge e1;
    e1.src = 0;
    e1.dest = 7;
    e1.weight = 8;
    insert(&(g->adjList[e1.src]), e1);
    struct Edge e1_rev;
    e1_rev.src = 7;
    e1_rev.dest = 0;
    e1_rev.weight = 8;
    insert(&(g->adjList[e1_rev.src]), e1_rev);
                                  
    // add edge 1-7
    struct Edge e2;
    e2.src = 1;
    e2.dest = 7;
    e2.weight = 11;
    insert(&(g->adjList[e2.src]), e2);
    struct Edge e2_rev;
    e2_rev.src = 7;
    e2_rev.dest = 1;
    e2_rev.weight = 11;
    insert(&(g->adjList[e2_rev.src]), e2_rev);
                                                    
    // add edge 7-8
    struct Edge e3;
    e3.src = 7;
    e3.dest = 8;
    e3.weight = 7;
    insert(&(g->adjList[e3.src]), e3);
    struct Edge e3_rev;
    e3_rev.src = 8;
    e3_rev.dest = 7;
    e3_rev.weight = 7;
    insert(&(g->adjList[e3_rev.src]), e3_rev);
     
    // add edge 1-2
    struct Edge e4;
    e4.src = 1;
    e4.dest = 2;
    e4.weight = 8;
    insert(&(g->adjList[e4.src]), e4);
    struct Edge e4_rev;
    e4_rev.src = 2;
    e4_rev.dest = 1;
    e4_rev.weight = 8;
    insert(&(g->adjList[e4_rev.src]), e4_rev);
    
    // add edge 2-8
    struct Edge e5;
    e5.src = 2;
    e5.dest = 8;
    e5.weight = 2;
    insert(&(g->adjList[e5.src]), e5);
    struct Edge e5_rev;
    e5_rev.src = 8;
    e5_rev.dest = 2;
    e5_rev.weight = 2;
    insert(&(g->adjList[e5_rev.src]), e5_rev);
    
    // add edge 6-8
    struct Edge e6;
    e6.src = 6;
    e6.dest = 8;
    e6.weight = 6;
    insert(&(g->adjList[e6.src]), e6);
    struct Edge e6_rev;
    e6_rev.src = 8;
    e6_rev.dest = 6;
    e6_rev.weight = 6;
    insert(&(g->adjList[e6_rev.src]), e6_rev);
    
    // add edge 5-6
    struct Edge e7;
    e7.src = 5;
    e7.dest = 6;
    e7.weight = 2;
    insert(&(g->adjList[e7.src]), e7);
    struct Edge e7_rev;
    e7_rev.src = 6;
    e7_rev.dest = 5;
    e7_rev.weight = 2;
    insert(&(g->adjList[e7_rev.src]), e7_rev);
    
    // add edge 2-5
    struct Edge e8;
    e8.src = 2;
    e8.dest = 5;
    e8.weight = 4;
    insert(&(g->adjList[e8.src]), e8);
    struct Edge e8_rev;
    e8_rev.src = 5;
    e8_rev.dest = 2;
    e8_rev.weight = 4;
    insert(&(g->adjList[e8_rev.src]), e8_rev);
    
    // add edge 2-3
    struct Edge e9;
    e9.src = 2;
    e9.dest = 3;
    e9.weight = 7;
    insert(&(g->adjList[e9.src]), e9);
    struct Edge e9_rev;
    e9_rev.src = 3;
    e9_rev.dest = 2;
    e9_rev.weight = 7;
    insert(&(g->adjList[e9_rev.src]), e9_rev);
    
    // add edge 3-5
    struct Edge e10;
    e10.src = 3;
    e10.dest = 5;
    e10.weight = 14;
    insert(&(g->adjList[e10.src]), e10);
    struct Edge e10_rev;
    e10_rev.src = 5;
    e10_rev.dest = 3;
    e10_rev.weight = 14;
    insert(&(g->adjList[e10_rev.src]), e10_rev);
    
    // add edge 3-4
    struct Edge e11;
    e11.src = 3;
    e11.dest = 4;
    e11.weight = 9;
    insert(&(g->adjList[e11.src]), e11);
    struct Edge e11_rev;
    e11_rev.src = 4;
    e11_rev.dest = 3;
    e11_rev.weight = 9;
    insert(&(g->adjList[e11_rev.src]), e11_rev);
    
    // add edge 4-5
    struct Edge e12;
    e12.src = 4;
    e12.dest = 5;
    e12.weight = 10;
    insert(&(g->adjList[e12.src]), e12);
    struct Edge e12_rev;
    e12_rev.src = 5;
    e12_rev.dest = 4;
    e12_rev.weight = 10;
    insert(&(g->adjList[e12_rev.src]), e12_rev);

    // add edge 7-6
    struct Edge e13;
    e13.src = 7;
    e13.dest = 6;
    e13.weight = 1;
    insert(&(g->adjList[e13.src]), e13);
    struct Edge e13_rev;
    e13_rev.src = 6;
    e13_rev.dest = 7;
    e13_rev.weight = 1;
    insert(&(g->adjList[e13_rev.src]), e13_rev);

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
    
    // add edge 0-7
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
                                  
    // add edge 1-7
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
                                                    
    // add edge 7-8
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
     
    // add edge 1-2
    struct Edge e4;
    e4.src = 2;
    e4.dest = 3;
    e4.weight = 4;
    insert(&(g->adjList[e4.src]), e4);
    struct Edge e4_rev;
    e4_rev.src = 3;
    e4_rev.dest = 2;
    e4_rev.weight = 4;
    insert(&(g->adjList[e4_rev.src]), e4_rev);**/
    
    //
    //Graph g = createSevenCycleGraph();
    Graph g = createGeeksGraph();

    for (int i = 0; i < 7; i++) {
       ListNode edgeNode = g->adjList[i];
       printf("Vertex %d ", i);
       while(edgeNode != NULL) {
        printf("Dest: %d\n", edgeNode->e.dest);
        edgeNode = edgeNode->next;
       }
    }

    find_MST(g);
                                                                              
    return 0;
}
