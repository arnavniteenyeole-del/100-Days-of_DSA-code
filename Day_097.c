#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start, end;
};

int cmpStart(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void push(int heap[], int* size, int val) {
    heap[*size] = val;
    int i = (*size)++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

int pop(int heap[], int* size) {
    int top = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, s = i;
        if (l < *size && heap[l] < heap[s]) s = l;
        if (r < *size && heap[r] < heap[s]) s = r;
        if (s == i) break;
        swap(&heap[i], &heap[s]);
        i = s;
    }
    return top;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(struct Interval), cmpStart);

    int heap[1000], size = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        while (size > 0 && heap[0] <= arr[i].start)
            pop(heap, &size);

        push(heap, &size, arr[i].end);

        if (size > maxRooms)
            maxRooms = size;
    }

    printf("%d", maxRooms);
    return 0;
}