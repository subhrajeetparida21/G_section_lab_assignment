#include <stdio.h>
#include <stdlib.h>
// Function to find the transpose of a sparse matrix
void transpose_sparse(int sparse[][3], int non_zero, int size) {
    int trans[non_zero][3];

    for (int i = 0; i < non_zero; i++) {
        trans[i][0] = sparse[i][1];
        trans[i][1] = sparse[i][0];
        trans[i][2] = sparse[i][2];
    }
    printf("\ntransposed sparse matrix:\n");
    printf("row\tcol\tvalue\n");
    printf("%d\t%d\t%d\n", size, size, non_zero);
    for (int i = 0; i < non_zero; i++) {
        printf("%d\t%d\t%d\n", trans[i][0], trans[i][1], trans[i][2]);
    }
}
int main() {
    int size, max;
    printf("enter the size of the square matrix: ");
    scanf("%d", &size);
    printf("enter the maximum number of non-zero elements: ");
    scanf("%d", &max);
    int mat[size][size];
    int sparse[max][3];
    int non_zero = 0, zero_count = 0;
    // Input matrix elements
    printf("enter the elements:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 0)
                zero_count++;
            else
                non_zero++;
        }
    }
    // Display matrix
    printf("the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    // Check if it's a sparse matrix
    if (non_zero > zero_count) {
        printf("\nnot a sparse matrix\n");
        return 0;
    }
    // Convert to sparse matrix representation
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mat[i][j] != 0) {
                if (k >= max) {
                    printf("\nerror: exceeded the maximum number of non-zero elements!\n");
                    return 1;
                }
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    // Print sparse representation
    printf("\nsparse representation:\n");
    printf("row\tcol\tvalue\n");
    printf("%d\t%d\t%d\n", size, size, non_zero);
    for (int i = 0; i < non_zero; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
    // Transpose the sparse matrix
    transpose_sparse(sparse, non_zero, size);
    return 0;
}
