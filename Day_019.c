#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int absVal(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int bestSum = INT_MAX;
    int x = arr[left], y = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (absVal(sum) < absVal(bestSum)) {
            bestSum = sum;
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            // Perfect case: sum == 0
            break;
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}