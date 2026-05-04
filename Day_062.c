#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
        newNode1->v = v;
        newNode1->next = adj[u];
        adj[u] = newNode1;

        struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
        newNode2->v = u;
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf(" %d", temp->v);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}