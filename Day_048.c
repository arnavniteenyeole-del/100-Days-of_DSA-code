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

int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) {
        printf("0");
        return 0;
    }

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

    printf("%d", countLeaves(nodes[0]));
    return 0;
}