#include <stdio.h>

#define MAX_VERTICES 10

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int num_vertices;

void initialize_graph() {
    int i, j;
    num_vertices = 0;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
}

void add_edge(int start_vertex, int end_vertex) {
    adjacency_matrix[start_vertex][end_vertex] = 1;
    adjacency_matrix[end_vertex][start_vertex] = 1;
}

void print_graph() {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_edges, i, start_vertex, end_vertex;
    initialize_graph();
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    for (i = 0; i < num_edges; i++) {
        printf("Enter edge %d (start_vertex end_vertex): ", i+1);
        scanf("%d %d", &start_vertex, &end_vertex);
        add_edge(start_vertex, end_vertex);
    }
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    print_graph();
    return 0;
}
