#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
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

    struct Node* q[n];
    int front = 0, rear = 0;
    q[rear++] = nodes[0];

    int leftToRight = 1;

    while (front < rear) {
        int sz = rear - front;
        int temp[sz];

        for (int i = 0; i < sz; i++) {
            struct Node* cur = q[front++];
            int idx = leftToRight ? i : (sz - 1 - i);
            temp[idx] = cur->data;

            if (cur->left) q[rear++] = cur->left;
            if (cur->right) q[rear++] = cur->right;
        }

        for (int i = 0; i < sz; i++) {
            printf("%d", temp[i]);
            if (!(front == rear && i == sz - 1)) printf(" ");
        }

        leftToRight = !leftToRight;
    }

    return 0;
}