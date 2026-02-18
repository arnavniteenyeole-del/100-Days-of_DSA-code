#include <stdio.h>

struct freq {
    int num;
    int frequency;
};

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    struct freq f[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        f[i].frequency = -1;   // mark uncounted
    }

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                f[j].frequency = 0;  // mark as counted
            }
        }
        if (f[i].frequency != 0) {
            f[i].num = arr[i];
            f[i].frequency = count;
        }
    }

    printf("\nElement  Frequency\n");
    for (int i = 0; i < n; i++) {
        if (f[i].frequency != 0) {
            printf("%d\t   %d\n", f[i].num, f[i].frequency);
        }
    }

    return 0;
}
