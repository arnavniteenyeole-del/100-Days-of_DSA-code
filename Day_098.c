#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start, end;
};

int cmp(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(struct Interval), cmp);

    struct Interval res[n];
    int idx = 0;

    res[idx++] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= res[idx - 1].end) {
            if (arr[i].end > res[idx - 1].end)
                res[idx - 1].end = arr[i].end;
        } else {
            res[idx++] = arr[i];
        }
    }

    for (int i = 0; i < idx; i++) {
        printf("%d %d", res[i].start, res[i].end);
        if (i != idx - 1) printf("\n");
    }

    return 0;
}