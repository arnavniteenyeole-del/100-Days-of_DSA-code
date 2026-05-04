#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        prefix[i] = sum;
    }

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (prefix[i] == 0 && i + 1 > maxLen)
            maxLen = i + 1;

        for (int j = i + 1; j < n; j++) {
            if (prefix[j] - prefix[i] == 0 && j - i > maxLen)
                maxLen = j - i;
        }
    }

    printf("%d", maxLen);
    return 0;
}