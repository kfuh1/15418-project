typedef int Vertex;

struct Edge {
    Vertex src;
    Vertex dest;
    int weight;
};
//typedef struct Edge Edge;

struct graph {
    int num_nodes;
    int num_edges;

    Edge* edges;
};
typedef graph* Graph;

int get_num_nodes(Graph g){
    return g->num_nodes;
}

int get_num_edges(Graph g){
    return g->num_edges;
}
