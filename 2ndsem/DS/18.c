#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int distance[MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int source, int num_nodes) {
	int i,j,k;
    // Initialize distance array with infinity for all nodes except source
    for (i = 0; i < num_nodes; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    // Visit every node
    for (i = 0; i < num_nodes; i++) {
        int min_distance = INT_MAX;
        int min_node = -1;

        // Find unvisited node with minimum distance
        for (j = 0; j < num_nodes; j++) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                min_node = j;
            }
        }

        // Mark node as visited
        visited[min_node] = 1;

        // Update distances of adjacent nodes
        for (k = 0; k < num_nodes; k++) {
            if (!visited[k] && graph[min_node][k] > 0 && distance[min_node] != INT_MAX &&
                distance[min_node] + graph[min_node][k] < distance[k]) {
                distance[k] = distance[min_node] + graph[min_node][k];
            }
        }
    }
}

int main() {
	int i,j;
    int num_nodes, num_edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    // Initialize graph with all zeroes
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            graph[i][j] = 0;
        }
    }

    // Populate graph with edges and weights
    for (i = 0; i < num_edges; i++) {
        int start, end, weight;
        printf("Enter edge %d (start, end, weight): ", i + 1);
        scanf("%d %d %d", &start, &end, &weight);
        graph[start][end] = weight;
    }

    int source;
    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstra(source, num_nodes);

    printf("Shortest distances from node %d:\n", source);
    for (i = 1; i <num_nodes; i++) {
        printf("%d: %d\n", i, distance[i]);
    }

    return 0;
}
