#include <stdio.h>
#include <limits.h>

// Function to print the solution matrix
void printSolution(int V, int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Floyd's algorithm to find shortest paths between all pairs
void floydWarshall(int V, int graph[][V]) {
    int dist[V][V];  // Output matrix that will have the shortest distances between every pair of vertices

    // Initialize dist[][] with the same values as graph[][]
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Iterate through all vertices as intermediate nodes
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(V, dist);
}

int main() {
    int V;

    // Get number of vertices from user
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Declare adjacency matrix graph[V][V]
    int graph[V][V];

    // Get the adjacency matrix from user
    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)  // Replace 0 with INF for non-diagonal elements
                graph[i][j] = INT_MAX;
        }
    }

    // Call the Floyd's algorithm function
    floydWarshall(V, graph);

    return 0;
}
