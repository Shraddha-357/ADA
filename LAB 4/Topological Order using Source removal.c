#include <stdio.h>
#include <stdlib.h>

int st[100];
int top = -1;

void degree(int adj[][20], int n) {
    int indegree[20];
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + adj[i][j];
        }
        indegree[j] = sum;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            top++;
            st[top] = i;
        }
    }

    while (top != -1) {
        int u = st[top];
        top--;
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    top++;
                    st[top] = v;
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int adj[20][20];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Topological order of nodes: ");
    degree(adj, n);

    return 0;
}
