#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unordered_map>

#include "graph.h"

#define MAX_WEIGHT 50

Graph instantiate_graph(int V, int E){
    Graph g = new graph;
    g->num_nodes = V;
    g->num_edges = E;
    g->offsets = new int[V];
    g->edges = new Vertex[E];
    g->weights = new int[E];
    return g;
}

void sort_edges(Edge **edges){
    //TODO write some kind of sort function
}
Graph create_graph(int V, int E, int seed) {
    Graph g = instantiate_graph(V, 2 * E);
    srand(seed);
    Edge *edges = new Edge[2 * E];
    
    std::unordered_map<std::string,int> edgeMap;

    int count = 0;
    int arr_idx = 0;
    while(count < E){
        int v1 = rand() % V;
        int v2 = rand() % V;
        int weight = (rand() % MAX_WEIGHT) + 1;
        if(v1 == v2)
            continue;
        //this is super hacky but idk what else to use as key in map
        std::string s = std::to_string(v1) + "," + std::to_string(v2);
        //edge already exists
        if(edgeMap.find(s) != edgeMap.end())
            continue;

        edgeMap.insert(std::pair<std::string,int>(s,1));

        Edge e1, e2;
        e1.src = v1;
        e1.dest = v2;
        e1.weight = weight; 
        e2.src = v2;
        e2.dest = v1;
        e2.weight = weight;
        edges[arr_idx] = e1;
        arr_idx++;
        edges[arr_idx] = e2;
        arr_idx++;
        count++;
    }
    sort_edges(&edges);

    int prev_src = 0;
    g->offsets[0] = 0;
    for(int i = 0; i < 2 * E; i++){
        Edge e = edges[i];
        g->weights[i] = e.weight;
        if(e.src != prev_src){
            //assumig our sort is correct this should work
            g->offsets[e.src] = i;
        }
            
    }
    return g;
}

