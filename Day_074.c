#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][101];
    for (int i = 0; i < n; i++)
        scanf("%s", names[i]);

    char unique[n][101];
    int count[n];
    int u = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < u; j++) {
            if (strcmp(unique[j], names[i]) == 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            count[found]++;
        } else {
            strcpy(unique[u], names[i]);
            count[u] = 1;
            u++;
        }
    }

    int max = -1;
    char result[101];

    for (int i = 0; i < u; i++) {
        if (count[i] > max) {
            max = count[i];
            strcpy(result, unique[i]);
        } else if (count[i] == max) {
            if (strcmp(unique[i], result) < 0)
                strcpy(result, unique[i]);
        }
    }

    printf("%s %d", result, max);
    return 0;
}