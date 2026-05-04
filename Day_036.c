#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

void enqueue(int x) {
    if (size == MAX) return;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    size++;
}

void dequeue() {
    if (size == 0) return;
    front = (front + 1) % MAX;
    size--;
}

int main() {
    int n, m, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    int count = size;
    int i = front;

    while (count--) {
        printf("%d", queue[i]);
        if (count) printf(" ");
        i = (i + 1) % MAX;
    }

    return 0;
}