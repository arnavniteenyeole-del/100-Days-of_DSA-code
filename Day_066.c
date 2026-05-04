#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[1000];
int visited[1000], recStack[1000];

void addEdge(int u, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;
}

int dfs(int u) {
    visited[u] = 1;
    recStack[u] = 1;

    struct Node* temp = adj[u];
    while (temp) {
        int v = temp->v;
        if (!visited[v]) {
            if (dfs(v)) return 1;
        } else if (recStack[v]) {
            return 1;
        }
        temp = temp->next;
    }

    recStack[u] = 0;
    return 0;
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}