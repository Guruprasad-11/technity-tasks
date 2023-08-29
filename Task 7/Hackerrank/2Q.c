#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr[][100], int n) {
    int left_diag_sum = 0;
    int right_diag_sum = 0;

    for (int i = 0; i < n; i++) {
        left_diag_sum += arr[i][i];
        right_diag_sum += arr[i][n - i - 1];
    }

    return abs(left_diag_sum - right_diag_sum);
}

int main() {
    int n;
    scanf("%d", &n);

    int matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result = diagonalDifference(matrix, n);

    printf("%d\n", result);

    return 0;
}
