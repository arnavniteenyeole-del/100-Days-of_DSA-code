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

struct Node* build(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end) return NULL;

    struct Node* root = createNode(preorder[(*preIndex)++]);

    if (start == end) return root;

    int idx = search(inorder, start, end, root->data);

    root->left = build(preorder, inorder, start, idx - 1, preIndex);
    root->right = build(preorder, inorder, idx + 1, end, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = build(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}