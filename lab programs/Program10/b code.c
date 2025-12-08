#include <stdio.h>

#define MAX 10

// DFS function
void DFS(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            DFS(adj, visited, i, n);
        }
    }
}

int main() {
    int n; // number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int visited[MAX] = {0};

    // Start DFS from vertex 0
    DFS(adj, visited, 0, n);

    // Check if all vertices are visited
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The graph is CONNECTED.\n");
    else
        printf("The graph is NOT CONNECTED.\n");

    return 0;
}
