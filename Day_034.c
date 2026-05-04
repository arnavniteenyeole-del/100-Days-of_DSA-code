#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    return newNode;
}

struct Node* pop(struct Node* top, int* val) {
    if (top == NULL) return NULL;
    struct Node* temp = top;
    *val = temp->data;
    top = top->next;
    free(temp);
    return top;
}

int main() {
    char expr[200];
    fgets(expr, sizeof(expr), stdin);

    struct Node* top = NULL;
    char* token = strtok(expr, " \n");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && strlen(token) > 1)) {
            top = push(top, atoi(token));
        } else {
            int b, a;
            top = pop(top, &b);
            top = pop(top, &a);

            if (token[0] == '+') top = push(top, a + b);
            else if (token[0] == '-') top = push(top, a - b);
            else if (token[0] == '*') top = push(top, a * b);
            else if (token[0] == '/') top = push(top, a / b);
        }
        token = strtok(NULL, " \n");
    }

    int result;
    top = pop(top, &result);
    printf("%d", result);

    return 0;
}