#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int mat[100][100];  // assuming max <= 100
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {

        // Top row
        for (int j = left; j <= right; j++) {
            printf("%d ", mat[top][j]);
        }
        top++;

        // Right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", mat[i][right]);
        }
        right--;

        // Bottom row (if exists)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                printf("%d ", mat[bottom][j]);
            }
            bottom--;
        }

        // Left column (if exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", mat[i][left]);
            }
            left++;
        }
    }

    return 0;
}
