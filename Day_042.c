#include <stdio.h>

#define MAX 1000

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1, size = 0;
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
    size++;
}

int dequeue() {
    int val = queue[front++];
    size--;
    return val;
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    while (size > 0) {
        push(dequeue());
    }

    while (top >= 0) {
        enqueue(pop());
    }

    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i != rear) printf(" ");
    }

    return 0;
}