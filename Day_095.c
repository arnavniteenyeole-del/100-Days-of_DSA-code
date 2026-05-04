#include <stdio.h>
#include <stdlib.h>

struct Node {
    float val;
    struct Node* next;
};

void insertSorted(struct Node** head, float val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;

    if (*head == NULL || (*head)->val >= val) {
        node->next = *head;
        *head = node;
        return;
    }

    struct Node* curr = *head;
    while (curr->next && curr->next->val < val)
        curr = curr->next;

    node->next = curr->next;
    curr->next = node;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    struct Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n);
        insertSorted(&buckets[idx], arr[i]);
    }

    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp) {
            printf("%.6f", temp->val);
            printf(" ");
            temp = temp->next;
        }
    }

    return 0;
}