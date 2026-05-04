#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

struct Node* lca(struct Node* root, int p, int q) {
    if (!root) return NULL;
    if (p < root->data && q < root->data)
        return lca(root->left, p, q);
    if (p > root->data && q > root->data)
        return lca(root->right, p, q);
    return root;
}

int main() {
    int n, x, p, q;
    scanf("%d", &n);

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &p, &q);

    struct Node* res = lca(root, p, q);
    if (res) printf("%d", res->data);

    return 0;
}