#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int mat[100][100];  // assuming max size <= 100 for simplicity

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Condition 1: Must be square
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Condition 2: Check symmetry
    int isSymmetric = 1;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
