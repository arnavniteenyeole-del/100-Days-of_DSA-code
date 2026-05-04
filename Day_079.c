#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[1001];

struct Pair {
    int node, dist;
};

struct Pair heap[10000];
int size = 0;

void swap(struct Pair* a, struct Pair* b) {
    struct Pair t = *a;
    *a = *b;
    *b = t;
}

void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    int i = size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].dist <= heap[i].dist) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

struct Pair pop() {
    struct Pair top = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, s = i;
        if (l < size && heap[l].dist < heap[s].dist) s = l;
        if (r < size && heap[r].dist < heap[s].dist) s = r;
        if (s == i) break;
        swap(&heap[i], &heap[s]);
        i = s;
    }
    return top;
}

void addEdge(int u, int v, int w) {
    struct Node* e1 = (struct Node*)malloc(sizeof(struct Node));
    e1->v = v;
    e1->w = w;
    e1->next = adj[u];
    adj[u] = e1;

    struct Node* e2 = (struct Node*)malloc(sizeof(struct Node));
    e2->v = u;
    e2->w = w;
    e2->next = adj[v];
    adj[v] = e2;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    int dist[1001];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        struct Pair p = pop();
        int u = p.node;

        if (p.dist > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF");
        else printf("%d", dist[i]);
        if (i != n) printf(" ");
    }

    return 0;
}