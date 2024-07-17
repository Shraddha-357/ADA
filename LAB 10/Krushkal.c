#include <stdio.h>

#define INF 9999
#define MAX 10

int find(int parent[], int i) {
    while (parent[i] != 0) {
        i = parent[i];
    }
    return i;
}

void unionSets(int parent[], int u, int v) {
    parent[v] = u;
}

void kruskal(int c[MAX][MAX], int n) {
    int parent[MAX], ne = 0;
    int mincost = 0;

    for (int i = 0; i < n; i++) {
        parent[i] = 0;
    }

    printf("Edges in the minimum spanning tree are:\n");

    while (ne < n - 1) {
        int min = INF;
        int a = -1, b = -1, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] < min) {
                    min = c[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(parent, u);
        v = find(parent, v);

        if (u != v) {
            printf("%d - %d: %d\n", a, b, min);
            unionSets(parent, u, v);
            ne++;
            mincost += min;
        }

        c[a][b] = c[b][a] = INF;
    }

    printf("Minimum cost = %d\n", mincost);
}

int main() {
    int c[MAX][MAX], n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0) {
                c[i][j] = INF;
            }
        }
    }

    kruskal(c, n);

    return 0;
}
