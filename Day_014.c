#include <stdio.h>

int main() {
    int r, c;

    printf("Enter rows and columns: ");
    if (scanf("%d %d", &r, &c) != 2) {
        printf("Invalid input for dimensions\n");
        return 0;
    }

    if (r <= 0 || c <= 0) {
        printf("Rows and columns must be positive\n");
        return 0;
    }

    if (r != c) {
        printf("Not a square matrix\n");
        return 0;
    }

    int matrix[r][c];

    printf("Enter %d elements:\n", r * c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid matrix element input\n");
                return 0;
            }
        }
    }

    printf("Matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Identity Matrix Check
    int isIdentity = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if (!isIdentity) break;
    }

    if (isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
