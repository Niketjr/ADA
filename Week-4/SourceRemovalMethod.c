#include <stdio.h>
#include <stdlib.h>

void topologicalSort(int **a, int n) {
int indegree[n], s[n], top = -1, T[n], k = 0;

// Compute in-degrees of all vertices
for (int j = 0; j < n; j++) {
int sum = 0;
for (int i = 0; i < n; i++) {
sum += a[i][j];
}
indegree[j] = sum;
}

// Initialize stack with vertices of in-degree 0
for (int i = 0; i < n; i++) {
if (indegree[i] == 0) {
s[++top] = i;
}
}

// Process vertices in stack
while (top != -1) {
int u = s[top--];
T[k++] = u;

// Decrease the in-degree of adjacent vertices
for (int v = 0; v < n; v++) {
if (a[u][v] == 1) {
indegree[v]--;
if (indegree[v] == 0) {
s[++top] = v;
}
}
}
}

// Print the topological order
printf("Topological Order: ");
for (int i = 0; i < k; i++) {
printf("%d ", T[i]);
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
topologicalSort(a, n);

// Free dynamically allocated memory
for (int i = 0; i < n; i++) {
free(a[i]);
}
free(a);

return 0;
}
