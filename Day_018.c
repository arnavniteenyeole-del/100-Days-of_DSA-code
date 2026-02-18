#include <stdio.h>

void reverse(int arr[], int left, int right) {
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void rotatearr(int arr[], int n, int k) {
    if (n == 0) return;

    k = k % n;  // handle k > n

    // Reverse the whole array
    reverse(arr, 0, n - 1);

    // Reverse first k elements
    reverse(arr, 0, k - 1);

    // Reverse remaining elements
    reverse(arr, k, n - 1);
}

int main() {
    int n, k;

    printf("Input number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Input array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to rotate array by: ");
    scanf("%d", &k);

    printf("Entered Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    rotatearr(arr, n, k);

    printf("Rotated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
