#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int dq[MAX];
int front = 0, rear = -1, size = 0;

void push_front(int x) {
    if (size == MAX) return;
    front = (front - 1 + MAX) % MAX;
    dq[front] = x;
    if (size == 0) rear = front;
    size++;
}

void push_back(int x) {
    if (size == MAX) return;
    rear = (rear + 1) % MAX;
    dq[rear] = x;
    if (size == 0) front = rear;
    size++;
}

void pop_front() {
    if (size == 0) return;
    front = (front + 1) % MAX;
    size--;
}

void pop_back() {
    if (size == 0) return;
    rear = (rear - 1 + MAX) % MAX;
    size--;
}

int get_front() {
    if (size == 0) return -1;
    return dq[front];
}

int get_back() {
    if (size == 0) return -1;
    return dq[rear];
}

int is_empty() {
    return size == 0;
}

int get_size() {
    return size;
}

void clear_deque() {
    front = 0;
    rear = -1;
    size = 0;
}

void reverse_deque() {
    int i = front, j = rear;
    for (int k = 0; k < size / 2; k++) {
        int temp = dq[i];
        dq[i] = dq[j];
        dq[j] = temp;
        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

void sort_deque() {
    int arr[MAX];
    int idx = 0;
    int i = front;
    for (int k = 0; k < size; k++) {
        arr[idx++] = dq[i];
        i = (i + 1) % MAX;
    }
    for (int a = 0; a < idx - 1; a++) {
        for (int b = a + 1; b < idx; b++) {
            if (arr[a] > arr[b]) {
                int t = arr[a];
                arr[a] = arr[b];
                arr[b] = t;
            }
        }
    }
    front = 0;
    rear = idx - 1;
    size = idx;
    for (int k = 0; k < idx; k++) dq[k] = arr[k];
}

int main() {
    int n, x;
    char op[20];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", get_front());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", get_back());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", is_empty());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", get_size());
        } else if (strcmp(op, "clear") == 0) {
            clear_deque();
        } else if (strcmp(op, "reverse") == 0) {
            reverse_deque();
        } else if (strcmp(op, "sort") == 0) {
            sort_deque();
        }
    }

    int i = front;
    for (int k = 0; k < size; k++) {
        printf("%d", dq[i]);
        if (k != size - 1) printf(" ");
        i = (i + 1) % MAX;
    }

    return 0;
}