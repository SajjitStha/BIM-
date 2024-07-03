#include <stdio.h>
#include <stdlib.h>

#define V 5 // number of vertices
#define E 7 // number of edges

int parent[V];
int rank[V];

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int num_vertices, num_edges;
    struct Edge* edges;
};

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (parent[v] != v) {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        if (rank[u] < rank[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        parent[v] = u;
        if (rank[u] == rank[v]) {
            rank[u]++;
        }
    }
}

int compare_edges(const void* a, const void* b) {
    struct Edge* a_edge = (struct Edge*)a;
    struct Edge* b_edge = (struct Edge*)b;
    return a_edge->weight - b_edge->weight;
}

void kruskal_mst(struct Graph* graph) {
    int i, j, u, v;
    for (i = 0; i < graph->num_vertices; i++) {
        make_set(i);
    }
    qsort(graph->edges, graph->num_edges, sizeof(struct Edge), compare_edges);
    printf("Edge \tWeight\n");
    for (i = 0; i < graph->num_edges; i++) {
        u = graph->edges[i].src;
        v = graph->edges[i].dest;
        if (find_set(u) != find_set(v)) {
            union_sets(u, v);
            printf("%d - %d \t%d\n", u, v, graph->edges[i].weight);
        }
    }
}

int main() {
    struct Edge edges[E] = {
        { 0, 1, 2 },
        { 0, 3, 6 },
        { 1, 2, 3 },
        { 1, 3, 8 },
        { 1, 4, 5 },
        { 2, 4, 7 },
        { 3, 4, 9 }
    };
    struct Graph graph = { V, E, edges };
    kruskal_mst(&graph);
    return 0;
}
