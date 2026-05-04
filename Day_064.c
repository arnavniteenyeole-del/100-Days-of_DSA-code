#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[1000];
int visited[1000];

void addEdge(int u, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;
}

void bfs(int s) {
    int q[1000], front = 0, rear = 0;
    visited[s] = 1;
    q[rear++] = s;

    while (front < rear) {
        int u = q[front++];
        printf("%d ", u);
        struct Node* temp = adj[u];
        while (temp) {
            if (!visited[temp->v]) {
                visited[temp->v] = 1;
                q[rear++] = temp->v;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, u, v, s;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    scanf("%d", &s);

    bfs(s);

    return 0;
}