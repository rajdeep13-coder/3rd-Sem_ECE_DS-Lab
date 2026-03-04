#include <stdio.h>

#define MAX 10

int main() {
    int adj[MAX][MAX];
    int vertices, edges;
    int i, j, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize matrix with 0
    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;   // remove this line for directed graph
    }

    // Display adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}