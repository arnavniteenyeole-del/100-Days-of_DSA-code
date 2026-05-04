#include <stdio.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[1001][1001];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int key[1001];
    int visited[1001] = {0};

    for (int i = 1; i <= n; i++)
        key[i] = INT_MAX;

    key[1] = 0;

    int total = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || key[j] < key[u]))
                u = j;
        }

        visited[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !visited[v] && adj[u][v] < key[v])
                key[v] = adj[u][v];
        }
    }

    printf("%d", total);
    return 0;
}