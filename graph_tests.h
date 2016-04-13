#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "graph.h"

Graph createGraph(int V, int E)
{
    Graph g = new graph;
    g->num_nodes = V;
    g->num_edges = E;
    g->adjList = new ListNode[2*E];
    return g;
}

// Crazy graph
Graph createCrazyGraph() {
    Graph g = createGraph(12,13);

    struct Edge e0;
    e0.src = 0;
    e0.dest = 1;
    e0.weight = 5;
    insert(&(g->adjList[e0.src]), e0);
    struct Edge e0_rev;
    e0_rev.src = 1;
    e0_rev.dest = 0;
    e0_rev.weight = 5;
    insert(&(g->adjList[e0_rev.src]), e0_rev);
    
    struct Edge e1;
    e1.src = 1;
    e1.dest = 2;
    e1.weight = 4;
    insert(&(g->adjList[e1.src]), e1);
    struct Edge e1_rev;
    e1_rev.src = 2;
    e1_rev.dest = 1;
    e1_rev.weight = 4;
    insert(&(g->adjList[e1_rev.src]), e1_rev);
    
    struct Edge e2;
    e2.src = 1;
    e2.dest = 4;
    e2.weight = 10;
    insert(&(g->adjList[e2.src]), e2);
    struct Edge e2_rev;
    e2_rev.src = 4;
    e2_rev.dest = 1;
    e2_rev.weight = 10;
    insert(&(g->adjList[e2_rev.src]), e2_rev);

    struct Edge e3;
    e3.src = 1;
    e3.dest = 5;
    e3.weight = 3;
    insert(&(g->adjList[e3.src]), e3);
    struct Edge e3_rev;
    e3_rev.src = 5;
    e3_rev.dest = 1;
    e3_rev.weight = 3;
    insert(&(g->adjList[e3_rev.src]), e3_rev);
    
    struct Edge e4;
    e4.src = 2;
    e4.dest = 5;
    e4.weight = 11;
    insert(&(g->adjList[e4.src]), e4);
    struct Edge e4_rev;
    e4_rev.src = 5;
    e4_rev.dest = 2;
    e4_rev.weight = 11;
    insert(&(g->adjList[e4_rev.src]), e4_rev);
    
    struct Edge e5;
    e5.src = 4;
    e5.dest = 5;
    e5.weight = 2;
    insert(&(g->adjList[e5.src]), e5);
    struct Edge e5_rev;
    e5_rev.src = 5;
    e5_rev.dest = 4;
    e5_rev.weight = 2;
    insert(&(g->adjList[e5_rev.src]), e5_rev);
    
    struct Edge e6;
    e6.src = 3;
    e6.dest = 4;
    e6.weight = 2;
    insert(&(g->adjList[e6.src]), e6);
    struct Edge e6_rev;
    e6_rev.src = 4;
    e6_rev.dest = 3;
    e6_rev.weight = 2;
    insert(&(g->adjList[e6_rev.src]), e6_rev);
    
    struct Edge e7;
    e7.src = 4;
    e7.dest = 7;
    e7.weight = 2;
    insert(&(g->adjList[e7.src]), e7);
    struct Edge e7_rev;
    e7_rev.src = 7;
    e7_rev.dest = 4;
    e7_rev.weight = 2;
    insert(&(g->adjList[e7_rev.src]), e7_rev);
    
    struct Edge e8;
    e8.src = 5;
    e8.dest = 6;
    e8.weight = 1;
    insert(&(g->adjList[e8.src]), e8);
    struct Edge e8_rev;
    e8_rev.src = 6;
    e8_rev.dest = 5;
    e8_rev.weight = 1;
    insert(&(g->adjList[e8_rev.src]), e8_rev);
    
    struct Edge e9;
    e9.src = 7;
    e9.dest = 8;
    e9.weight = 6;
    insert(&(g->adjList[e9.src]), e9);
    struct Edge e9_rev;
    e9_rev.src = 8;
    e9_rev.dest = 7;
    e9_rev.weight = 6;
    insert(&(g->adjList[e9_rev.src]), e9_rev);

    struct Edge e10;
    e10.src = 7;
    e10.dest = 9;
    e10.weight = 6;
    insert(&(g->adjList[e10.src]), e10);
    struct Edge e10_rev;
    e10_rev.src = 9;
    e10_rev.dest = 7;
    e10_rev.weight = 6;
    insert(&(g->adjList[e10_rev.src]), e10_rev);
    
    struct Edge e11;
    e11.src = 7;
    e11.dest = 10;
    e11.weight = 7;
    insert(&(g->adjList[e11.src]), e11);
    struct Edge e11_rev;
    e11_rev.src = 10;
    e11_rev.dest = 7;
    e11_rev.weight = 7;
    insert(&(g->adjList[e11_rev.src]), e11_rev);

    struct Edge e12;
    e12.src = 7;
    e12.dest = 11;
    e12.weight = 3;
    insert(&(g->adjList[e12.src]), e12);
    struct Edge e12_rev;
    e12_rev.src = 11;
    e12_rev.dest = 7;
    e12_rev.weight = 3;
    insert(&(g->adjList[e12_rev.src]), e12_rev);
    
    return g; 
}

Graph createStarGraph() {
    Graph g = createGraph(6,5);

    struct Edge e0;
    e0.src = 0;
    e0.dest = 5;
    e0.weight = 3;
    insert(&(g->adjList[e0.src]), e0);
    struct Edge e0_rev;
    e0_rev.src = 5;
    e0_rev.dest = 0;
    e0_rev.weight = 3;
    insert(&(g->adjList[e0_rev.src]), e0_rev);
    
    struct Edge e1;
    e1.src = 1;
    e1.dest = 5;
    e1.weight = 2;
    insert(&(g->adjList[e1.src]), e1);
    struct Edge e1_rev;
    e1_rev.src = 5;
    e1_rev.dest = 1;
    e1_rev.weight = 2;
    insert(&(g->adjList[e1_rev.src]), e1_rev);
    
    struct Edge e2;
    e2.src = 2;
    e2.dest = 5;
    e2.weight = 2;
    insert(&(g->adjList[e2.src]), e2);
    struct Edge e2_rev;
    e2_rev.src = 5;
    e2_rev.dest = 2;
    e2_rev.weight = 2;
    insert(&(g->adjList[e2_rev.src]), e2_rev);

    struct Edge e3;
    e3.src = 3;
    e3.dest = 5;
    e3.weight = 10;
    insert(&(g->adjList[e3.src]), e3);
    struct Edge e3_rev;
    e3_rev.src = 5;
    e3_rev.dest = 3;
    e3_rev.weight = 10;
    insert(&(g->adjList[e3_rev.src]), e3_rev);
    
    struct Edge e4;
    e4.src = 4;
    e4.dest = 5;
    e4.weight = 11;
    insert(&(g->adjList[e4.src]), e4);
    struct Edge e4_rev;
    e4_rev.src = 5;
    e4_rev.dest = 4;
    e4_rev.weight = 11;
    insert(&(g->adjList[e4_rev.src]), e4_rev);
  
    return g;
}

Graph createLineGraph() {
    Graph g = createGraph(5,4);

    struct Edge e0;
    e0.src = 0;
    e0.dest = 1;
    e0.weight = 3;
    insert(&(g->adjList[e0.src]), e0);
    struct Edge e0_rev;
    e0_rev.src = 1;
    e0_rev.dest = 0;
    e0_rev.weight = 3;
    insert(&(g->adjList[e0_rev.src]), e0_rev);
    
    struct Edge e1;
    e1.src = 1;
    e1.dest = 2;
    e1.weight = 2;
    insert(&(g->adjList[e1.src]), e1);
    struct Edge e1_rev;
    e1_rev.src = 2;
    e1_rev.dest = 1;
    e1_rev.weight = 2;
    insert(&(g->adjList[e1_rev.src]), e1_rev);
    
    struct Edge e2;
    e2.src = 2;
    e2.dest = 3;
    e2.weight = 2;
    insert(&(g->adjList[e2.src]), e2);
    struct Edge e2_rev;
    e2_rev.src = 3;
    e2_rev.dest = 2;
    e2_rev.weight = 2;
    insert(&(g->adjList[e2_rev.src]), e2_rev);

    struct Edge e3;
    e3.src = 3;
    e3.dest = 4;
    e3.weight = 10;
    insert(&(g->adjList[e3.src]), e3);
    struct Edge e3_rev;
    e3_rev.src = 4;
    e3_rev.dest = 3;
    e3_rev.weight = 11;
    insert(&(g->adjList[e3_rev.src]), e3_rev);

    return g;
}

Graph createFourCycleGraph() {
    Graph g = createGraph(4,4);

    struct Edge e0;
    e0.src = 0;
    e0.dest = 1;
    e0.weight = 3;
    insert(&(g->adjList[e0.src]), e0);
    struct Edge e0_rev;
    e0_rev.src = 1;
    e0_rev.dest = 0;
    e0_rev.weight = 3;
    insert(&(g->adjList[e0_rev.src]), e0_rev);
    
    struct Edge e1;
    e1.src = 1;
    e1.dest = 2;
    e1.weight = 2;
    insert(&(g->adjList[e1.src]), e1);
    struct Edge e1_rev;
    e1_rev.src = 2;
    e1_rev.dest = 1;
    e1_rev.weight = 2;
    insert(&(g->adjList[e1_rev.src]), e1_rev);
    
    struct Edge e2;
    e2.src = 2;
    e2.dest = 3;
    e2.weight = 2;
    insert(&(g->adjList[e2.src]), e2);
    struct Edge e2_rev;
    e2_rev.src = 3;
    e2_rev.dest = 2;
    e2_rev.weight = 2;
    insert(&(g->adjList[e2_rev.src]), e2_rev);

    struct Edge e3;
    e3.src = 3;
    e3.dest = 0;
    e3.weight = 10;
    insert(&(g->adjList[e3.src]), e3);
    struct Edge e3_rev;
    e3_rev.src = 0;
    e3_rev.dest = 3;
    e3_rev.weight = 11;
    insert(&(g->adjList[e3_rev.src]), e3_rev);

    return g;
}

Graph createSevenCycleGraph() {
    Graph g = createGraph(7,7);

    struct Edge e0;
    e0.src = 0;
    e0.dest = 1;
    e0.weight = 5;
    insert(&(g->adjList[e0.src]), e0);
    struct Edge e0_rev;
    e0_rev.src = 1;
    e0_rev.dest = 0;
    e0_rev.weight = 5;
    insert(&(g->adjList[e0_rev.src]), e0_rev);
    
    struct Edge e1;
    e1.src = 1;
    e1.dest = 2;
    e1.weight = 4;
    insert(&(g->adjList[e1.src]), e1);
    struct Edge e1_rev;
    e1_rev.src = 2;
    e1_rev.dest = 1;
    e1_rev.weight = 4;
    insert(&(g->adjList[e1_rev.src]), e1_rev);
    
    struct Edge e2;
    e2.src = 2;
    e2.dest = 3;
    e2.weight = 10;
    insert(&(g->adjList[e2.src]), e2);
    struct Edge e2_rev;
    e2_rev.src = 3;
    e2_rev.dest = 2;
    e2_rev.weight = 10;
    insert(&(g->adjList[e2_rev.src]), e2_rev);

    struct Edge e3;
    e3.src = 3;
    e3.dest = 4;
    e3.weight = 3;
    insert(&(g->adjList[e3.src]), e3);
    struct Edge e3_rev;
    e3_rev.src = 4;
    e3_rev.dest = 3;
    e3_rev.weight = 3;
    insert(&(g->adjList[e3_rev.src]), e3_rev);
    
    struct Edge e4;
    e4.src = 4;
    e4.dest = 5;
    e4.weight = 11;
    insert(&(g->adjList[e4.src]), e4);
    struct Edge e4_rev;
    e4_rev.src = 5;
    e4_rev.dest = 4;
    e4_rev.weight = 11;
    insert(&(g->adjList[e4_rev.src]), e4_rev);
    
    struct Edge e5;
    e5.src = 5;
    e5.dest = 6;
    e5.weight = 2;
    insert(&(g->adjList[e5.src]), e5);
    struct Edge e5_rev;
    e5_rev.src = 6;
    e5_rev.dest = 5;
    e5_rev.weight = 2;
    insert(&(g->adjList[e5_rev.src]), e5_rev);
    
    struct Edge e6;
    e6.src = 6;
    e6.dest = 0;
    e6.weight = 2;
    insert(&(g->adjList[e6.src]), e6);
    struct Edge e6_rev;
    e6_rev.src = 0;
    e6_rev.dest = 6;
    e6_rev.weight = 2;
    insert(&(g->adjList[e6_rev.src]), e6_rev);
     
    return g;
}
