#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) return 0;

    struct Node* nodes[n];
    for (int i = 0; i < n; i++)
        nodes[i] = createNode(arr[i]);

    int j = 1;
    for (int i = 0; i < n && j < n; i++) {
        if (nodes[i]) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }

    struct Pair queue[n];
    int front = 0, rear = 0;

    int min = 0, max = 0;
    int col[200][100];
    int count[200] = {0};

    queue[rear++] = (struct Pair){nodes[0], 100};

    while (front < rear) {
        struct Pair p = queue[front++];
        int hd = p.hd;

        col[hd][count[hd]++] = p.node->data;

        if (p.node->left) {
            queue[rear++] = (struct Pair){p.node->left, hd - 1};
            if (hd - 1 < min) min = hd - 1;
        }
        if (p.node->right) {
            queue[rear++] = (struct Pair){p.node->right, hd + 1};
            if (hd + 1 > max) max = hd + 1;
        }
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d", col[i][j]);
            if (j != count[i] - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}