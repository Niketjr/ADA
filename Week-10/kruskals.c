#include <stdio.h>
#include <limits.h>

int main() {
    printf("Enter number of nodes: ");
    int n;
    scanf("%d", &n);
    int c[n][n];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int ne = 0, minc = 0;
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Initialize each node to be its own parent
    }

    while (ne != n - 1) {
        int min = INT_MAX, a = -1, b = -1, u = -1, v = -1;

        // Find the minimum edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] < min) {
                    min = c[i][j];
                    u = i;
                    v = j;
                    a = i;
                    b = j;
                }
            }
        }

        // Find root of u and v
        while (parent[u] != u) {
            u = parent[u];
        }
        while (parent[v] != v) {
            v = parent[v];
        }

        // Check if including this edge forms a cycle
        if (u != v) {
            printf("%d - %d : %d\n", a+1, b+1, min);
            parent[v] = u; // Union operation
            ne++;
            minc += min;
        }

        // Mark the edge as visited
        c[a][b] = c[b][a] = INT_MAX;
    }

    printf("Minimum cost of spanning tree: %d\n", minc);

    return 0;
}
