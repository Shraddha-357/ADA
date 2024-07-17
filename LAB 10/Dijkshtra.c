#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int c[MAX][MAX], int n, int src) {
    int dist[MAX], vis[MAX], count, min, u;

    // Initialize distances and visited nodes
    for (int j = 0; j < n; j++) {
        dist[j] = c[src][j];
        vis[j] = 0;
    }

    dist[src] = 0;
    vis[src] = 1;
    count = 1;

    while (count != n) {
        min = INF;

        // Find the unvisited node with the smallest distance
        for (int j = 0; j < n; j++) {
            if (dist[j] < min && vis[j] != 1) {
                min = dist[j];
                u = j;
            }
        }

        vis[u] = 1;
        count++;

        // Update the distances of the neighbors of the selected node
        for (int j = 0; j < n; j++) {
            if (min + c[u][j] < dist[j] && vis[j] != 1) {
                dist[j] = min + c[u][j];
            }
        }
    }

    // Output the shortest distances
    printf("Shortest distances are:\n");
    for (int j = 0; j < n; j++) {
        printf("From %d to %d: %d\n", src, j, dist[j]);
    }
}

int main() {
    int c[MAX][MAX], n, src;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &src);

    dijkstra(c, n, src);

    return 0;
}
