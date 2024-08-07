#include <stdio.h>
#define MAX 100
#define INF 9999

void dijkstras(int c[MAX][MAX], int n, int src) {
    int dist[MAX];  // To store the shortest distance from src to each vertex
    int vis[MAX];   // To track if a vertex is visited
    int count, min, u, i, j;

    // Initialize distance and visited arrays
    for (i = 1; i <= n; i++) {
        dist[i] = c[src][i];
        vis[i] = 0;
    }

    dist[src] = 0;
    vis[src] = 1;
    count = 1;

    while (count != n) {
        min = INF;

        // Find the vertex with the minimum distance which is not yet visited
        for (j = 1; j <= n; j++) {
            if (dist[j] < min && vis[j] != 1) {
                min = dist[j];
                u = j;
            }
        }

        vis[u] = 1;
        count++;

        // Update the distances of the adjacent vertices of the selected vertex
        for (j = 1; j <= n; j++) {
            if ((min + c[u][j] < dist[j]) && (vis[j] != 1)) {
                dist[j] = min + c[u][j];
            }
        }
    }

    // Print the shortest distances from src to all vertices
    printf("Shortest distances from node %d:\n", src);
    for (i = 1; i <= n; i++) {
        printf("%d -> %d : %d\n", src, i, dist[i]);
    }
}

int main() {
    int n, src;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;
            }
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &src);

    dijkstras(cost, n, src);

    return 0;
}
