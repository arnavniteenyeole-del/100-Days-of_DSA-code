#include <stdio.h>
#include <stdlib.h>

int countZeroSumSubarrays(int arr[], int n) {
    int prefix_sum = 0;
    int count = 0;


    int size = 200001;           
    int offset = 100000;         
    int *freq = (int *)calloc(size, sizeof(int));

    // Initialize
    freq[offset] = 1;  // prefix_sum = 0

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if (freq[prefix_sum + offset] > 0) {
            count += freq[prefix_sum + offset];
        }

        freq[prefix_sum + offset]++;
    }

    free(freq);
    return count;
}

int main() {
    int n;

    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);

    printf("%d\n", result);

    free(arr);
    return 0;
}