#include <stdio.h>

#define max 10

void multiplySparseMatrices(int a[max][max], int b[max][max], int c[max][max], int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int mat[max][max], int row, int col) {
    printf("Result Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int inputMatrix(int mat[max][max], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at [%d][%d] (1 for landmine, 0 for empty space): ", i, j);
            if (scanf("%d", &mat[i][j]) != 1 || (mat[i][j] != 0 && mat[i][j] != 1)) {
                printf("Invalid input! Please enter 1 or 0.\n");
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int a[max][max], b[max][max], c[max][max];
    int n, m, p;

    printf("Enter dimensions of matrix A (rows cols): ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("Invalid dimensions for matrix A. Please enter positive integers.\n");
        return 1;
    }
    printf("Enter elements for matrix A:\n");
    if (!inputMatrix(a, n, m)) {
        return 1;
    }
    printf("Enter dimensions of matrix B (rows cols): ");
    if (scanf("%d %d", &m, &p) != 2 || m <= 0 || p <= 0) {
        printf("Invalid dimensions for matrix B. Please enter positive integers.\n");
        return 1;
    }
    if (m != n) {
        printf("Matrix multiplication is not possible. Number of columns of A must match number of rows of B.\n");
        return 1;
    }

    printf("Enter elements for matrix B:\n");
    if (!inputMatrix(b, m, p)) {
        return 1;
    }
    multiplySparseMatrices(a, b, c, n, m, p);
    printMatrix(c, n, p);

    return 0;
}
