#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int val, idx;
};

int counts[100000];

void merge(struct Pair arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int rightCount = 0;

    struct Pair temp[r - l + 1];

    while (i <= m && j <= r) {
        if (arr[i].val <= arr[j].val) {
            counts[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        counts[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= r)
        temp[k++] = arr[j++];

    for (int p = 0; p < k; p++)
        arr[l + p] = temp[p];
}

void mergeSort(struct Pair arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Pair arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
        counts[i] = 0;
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", counts[i]);
        if (i != n - 1) printf(" ");
    }

    return 0;
}