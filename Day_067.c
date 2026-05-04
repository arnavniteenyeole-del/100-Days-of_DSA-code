#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[1000];
int visited[1000];
int stack[1000];
int top = -1;

void addEdge(int u, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;
}

void dfs(int u) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->v])
            dfs(temp->v);
        temp = temp->next;
    }
    stack[++top] = u;
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
        if (!visited[i])
            dfs(i);
    }

    while (top != -1) {
        printf("%d", stack[top--]);
        if (top != -1) printf(" ");
    }

    return 0;
}