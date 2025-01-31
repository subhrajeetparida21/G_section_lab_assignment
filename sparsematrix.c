// #include<stdio.h>
// #include<stdlib.h>

// void transposeSparseMatrix(int** sparse, int non_zero) {
//     int** transposed = (int**)malloc(non_zero * sizeof(int*));
//     for(int i = 0; i < non_zero; i++) {
//         transposed[i] = (int*)malloc(3 * sizeof(int));
//     }
    
//     for(int i = 0; i < non_zero; i++) {
//         transposed[i][0] = sparse[i][1];
//         transposed[i][1] = sparse[i][0];
//         transposed[i][2] = sparse[i][2];
//     }
    
//     printf("\nTRANSPOSED SPARSE MATRIX:\n");
//     printf("ROW_INDEX\tCOL_INDEX\tVALUE\n");
//     printf("%d\t%d\t%d\n", 3, 3, non_zero);
//     for(int i = 0; i < non_zero; i++) {
//         printf("%d\t%d\t%d\n", transposed[i][0], transposed[i][1], transposed[i][2]);
//     }

//     for(int i = 0; i < non_zero; i++) {
//         free(transposed[i]);
//     }
//     free(transposed);
// }

// int main() {
//     int i, j;
    
//     // Allocate memory correctly
//     int** arr = (int**)malloc(3 * sizeof(int*));
//     for(i = 0; i < 3; i++) {
//         arr[i] = (int*)malloc(3 * sizeof(int));
//     }
    
//     printf("Enter the elements:\n");
//     for(i = 0; i < 3; i++) {
//         for(j = 0; j < 3; j++) {
//             scanf("%d", &arr[i][j]);
//         }
//     }

//     printf("The matrix:\n");
//     for(i = 0; i < 3; i++) {
//         for(j = 0; j < 3; j++) {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }

//     int zero = 0, non_zero = 0;
//     for(i = 0; i < 3; i++) {
//         for(j = 0; j < 3; j++) {
//             if(arr[i][j] == 0)
//                 zero++;
//             else
//                 non_zero++;
//         }
//     }

//     if(non_zero > zero) {
//         printf("\nNot a sparse matrix\n");
        
//         // Free allocated memory
//         for(i = 0; i < 3; i++) {
//             free(arr[i]);
//         }
//         free(arr);
        
//         return 0;
//     }

//     // Allocate memory for sparse representation correctly
//     int** sparse_represent = (int**)malloc(non_zero * sizeof(int*));
//     for(i = 0; i < non_zero; i++) {
//         sparse_represent[i] = (int*)malloc(3 * sizeof(int));
//     }

//     int k = 0;
//     for(i = 0; i < 3; i++) {
//         for(j = 0; j < 3; j++) {
//             if(arr[i][j] != 0) {
//                 sparse_represent[k][0] = i;
//                 sparse_represent[k][1] = j;
//                 sparse_represent[k][2] = arr[i][j];
//                 k++;
//             }
//         }
//     }

//     printf("SPARSE REPRESENTATION:\n");
//     printf("In order of: ROW_INDEX, COL_INDEX, VALUE\n");
//     printf("%d\t%d\t%d\n", 3, 3, non_zero);
//     for(i = 0; i < non_zero; i++) {
//         printf("%d\t%d\t%d\n", sparse_represent[i][0], sparse_represent[i][1], sparse_represent[i][2]);
//     }

//     // Transpose
//     transposeSparseMatrix(sparse_represent, non_zero);

//     // Free allocated memory
//     for(i = 0; i < 3; i++) {
//         free(arr[i]);
//     }
//     free(arr);
    
//     for(i = 0; i < non_zero; i++) {
//         free(sparse_represent[i]);
//     }
//     free(sparse_represent);
    
//     return 0;
// }


#include <stdio.h>

#define SIZE 3 // Size of the square matrix
#define MAX 10 // Maximum possible non-zero elements (adjust as needed)

// Function to find the transpose of a sparse matrix
void sparsearr(int sparse[MAX][3], int nz) {
    int trans[MAX][3]; // Renamed transposed → trans

    for (int i = 0; i < nz; i++) {
        trans[i][0] = sparse[i][1];  // Swap row & column
        trans[i][1] = sparse[i][0];
        trans[i][2] = sparse[i][2];
    }

    printf("\nTRANSPOSED SPARSE MATRIX:\n");
    printf("ROW\tCOL\tVALUE\n");
    printf("%d\t%d\t%d\n", SIZE, SIZE, nz);
    for (int i = 0; i < nz; i++) {
        printf("%d\t%d\t%d\n", trans[i][0], trans[i][1], trans[i][2]);
    }
}

int main() {
    int arr[SIZE][SIZE]; // Matrix
    int sparse[MAX][3];  // Sparse representation
    int nz = 0, zCount = 0;

    // Input matrix elements
    printf("Enter the elements:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0)
                zCount++;
            else
                nz++;
        }
    }

    // Display matrix
    printf("The matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Check if it's a sparse matrix
    if (nz > zCount) {
        printf("\nNot a sparse matrix\n");
        return 0;
    }

    // Convert to sparse matrix representation
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }

    // Print sparse representation
    printf("\nSPARSE REPRESENTATION:\n");
    printf("ROW\tCOL\tVALUE\n");
    printf("%d\t%d\t%d\n", SIZE, SIZE, nz);
    for (int i = 0; i < nz; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    // Transpose the sparse matrix
    sparsearr(sparse, nz);

    return 0;
}
