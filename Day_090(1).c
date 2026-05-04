#include <stdio.h>

int can(int arr[], int n, int k, int mid) {
    int painters = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return 0;

        if (sum + arr[i] <= mid) {
            sum += arr[i];
        } else {
            painters++;
            sum = arr[i];
            if (painters > k) return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int low = 0, high = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low) low = arr[i];
        high += arr[i];
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (can(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);
    return 0;
}