#include <stdio.h>
#include <stdlib.h>

// Function to convert a normal matrix into sparse representation
void convertToSparse(int rows, int cols, int mat[rows][cols], int sparse[][3], int *count) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    *count = k;
}

// Function to multiply two sparse matrices
void multiplySparse(int A[][3], int aCount, int B[][3], int bCount, int C[][3], int *cCount, int rA, int cA, int cB) {
    int res[rA][cB];

    for (int i = 0; i < rA; i++)
        for (int j = 0; j < cB; j++)
            res[i][j] = 0;

    // Multiply matrices
    for (int i = 0; i < aCount; i++) {
        for (int j = 0; j < bCount; j++) {
            if (A[i][1] == B[j][0]) {  // Column of A matches Row of B
                res[A[i][0]][B[j][1]] = res[A[i][0]][B[j][1]] +  A[i][2] * B[j][2];
               
            }
        }
    }

    // Convert result to sparse representation
    int k = 0;
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            if (res[i][j] != 0) {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = res[i][j];
                k++;
            }
        }
    }
    *cCount = k;
}

// Function to print sparse matrix
void printSparse(int sparse[][3], int count, int rows, int cols) {
    printf("%d\t%d\t%d\n", rows, cols, count);
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int rA, cA, rB, cB;

    // Input Matrix A
    printf("Enter rows and columns of A: ");
    scanf("%d %d", &rA, &cA);
    int A[rA][cA];
    printf("Enter elements of A:\n");
    for (int i = 0; i < rA; i++)
        for (int j = 0; j < cA; j++)
            scanf("%d", &A[i][j]);

    // Input Matrix B
    printf("Enter rows and columns of B: ");
    scanf("%d %d", &rB, &cB);
    int B[rB][cB];
    printf("Enter elements of B:\n");
    for (int i = 0; i < rB; i++)
        for (int j = 0; j < cB; j++)
            scanf("%d", &B[i][j]);

    // Check if multiplication is possible
    if (cA != rB) {
        printf("Multiplication not possible.\n");
        return 0;
    }

    // Convert matrices to sparse form
    int spA[rA * cA][3], spB[rB * cB][3], spC[rA * cB][3];
    int countA, countB, countC;
    
    convertToSparse(rA, cA, A, spA, &countA);
    convertToSparse(rB, cB, B, spB, &countB);

    printf("\nSparse Matrix A:\n");
    printSparse(spA, countA, rA, cA);

    printf("\nSparse Matrix B:\n");
    printSparse(spB, countB, rB, cB);

    // Multiply sparse matrices
    multiplySparse(spA, countA, spB, countB, spC, &countC, rA, cA, cB);

    // Print result
    printf("\nResultant Sparse Matrix:\n");
    printSparse(spC, countC, rA, cB);

    return 0;
}
