#include <stdio.h>
#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array
int stack[MAX];    // Stack for storing the topological order
int top = -1;      // Top of the stack
int n;             // Number of vertices

// Push function for the stack
void push(int v) {
    stack[++top] = v;
}

// Pop function for the stack
int pop() {
    return stack[top--];
}

// Depth-First Search function
void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    push(v);
}

// Function to perform topological sort
void topologicalSort() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int edges, start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read the edges
    for (int i = 0; i < edges; i++) {
        printf("Enter start and end vertices of edge %d: ", i + 1);
        scanf("%d %d", &start, &end);
        adj[start][end] = 1;
    }

    printf("Topological sort: ");
    topologicalSort();

    return 0;
}
