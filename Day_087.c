#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int x;
    scanf("%d", &x);

    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            ans = mid;
            break;
        } else if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}