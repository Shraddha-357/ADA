#include <stdio.h>
#include <limits.h>
#define N 4
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < N; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}
void printMST(int parent[], int graph[N][N]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < N; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}
void primMST(int graph[N][N]) {
    int parent[N];
    int key[N];
    int mstSet[N];
    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < N - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < N; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

int main() {
    /* Let us create the following graph
            10
        0--------1
        | \      |
       6| 5\     |15
        |   \    |
        2--------3
            4
    */
    int graph[N][N] = { { 0, 10, 6, 5 },
                        { 10, 0, 0, 15 },
                        { 6, 0, 0, 4 },
                        { 5, 15, 4, 0 } };
    primMST(graph);

    return 0;
}
