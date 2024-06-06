#include <stdio.h>
#include <stdlib.h>

void DFS(int u, int n, int **a, int *s, int *res, int *j) {
// Mark the current node as visited
s[u] = 1;

// Visit all adjacent vertices
for (int v = 0; v < n; v++) {
if (a[u][v] == 1 && s[v] == 0) {
DFS(v, n, a, s, res, j);
}
}

// Store the vertex in result array once completely explored
res[(*j)++] = u;
}

void topologicalOrder(int n, int **a) {
int s[n]; // Visited array
int res[n]; // Result array
int j = 0; // Index for result array

// Initialize visited array
for (int i = 0; i < n; i++) {
s[i] = 0;
}

// Process each vertex in the graph
for (int u = 0; u < n; u++) {
if (s[u] == 0) {
DFS(u, n, a, s, res, &j);
}
}

// Print the topological order in reverse order
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

// Dynamically allocate memory for adjacency matrix
int **a = (int **)malloc(n * sizeof(int *));
for (int i = 0; i < n; i++) {
a[i] = (int *)malloc(n * sizeof(int));
}

// Read adjacency matrix
printf("Enter the adjacency matrix:\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &a[i][j]);
}
}

// Perform topological sort
topologicalOrder(n, a);

// Free dynamically allocated memory
for (int i = 0; i < n; i++) {
free(a[i]);
}
free(a);

return 0;
}
