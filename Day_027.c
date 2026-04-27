#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at end
struct Node* insert(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    // Move pointer of longer list
    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++) p2 = p2->next;
    }

    // Traverse together
    while (p1 && p2) {
        if (p1 == p2)
            return p1;

        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insert(head1, x);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insert(head2, x);
    }

    // 🔥 Simulate intersection (based on value match)
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    while (temp2->next != NULL)
        temp2 = temp2->next;

    while (temp1 != NULL) {
        if (temp1->data == 30) {  // Example: connect at value 30
            temp2->next = temp1;
            break;
        }
        temp1 = temp1->next;
    }

    // Find intersection
    struct Node* result = getIntersection(head1, head2);

    if (result)
        printf("%d", result->data);
    else
        printf("No Intersection");

    return 0;
}