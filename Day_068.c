#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[1000];
int indegree[1000];

void addEdge(int u, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;
    indegree[v]++;
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int q[1000], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q[rear++] = i;

    int count = 0;

    while (front < rear) {
        int u = q[front++];
        printf("%d", u);
        count++;
        if (count < n) printf(" ");

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            if (--indegree[v] == 0)
                q[rear++] = v;
            temp = temp->next;
        }
    }

    return 0;
}