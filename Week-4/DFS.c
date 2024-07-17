#include <stdio.h>
#include <stdlib.h>

void DFS(int u, int n, int **a, int *s, int *res, int *j) {
    s[u] = 1;
    for (int v = 0; v < n; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            DFS(v, n, a, s, res, j);
        }
    }
    res[(*j)++] = u;
}

void topologicalOrder(int n, int **a) {
    int s[n];
    int res[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        s[i] = 0;
    }

    for (int u = 0; u < n; u++) {
        if (s[u] == 0) {
            DFS(u, n, a, s, res, &j);
        }
    }

    printf("Topological Order: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    topologicalOrder(n, a);

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
