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

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

struct Node* build(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    struct Node* root = createNode(postorder[(*postIndex)--]);

    if (start == end) return root;

    int idx = search(inorder, start, end, root->data);

    root->right = build(inorder, postorder, idx + 1, end, postIndex);
    root->left = build(inorder, postorder, start, idx - 1, postIndex);

    return root;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    struct Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}