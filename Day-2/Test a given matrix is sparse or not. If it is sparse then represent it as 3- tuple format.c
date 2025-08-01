#include <stdio.h>

int main() {
    int matrix[10][10], sparse[100][3];
    int rows, cols, i, j, count = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &rows, &cols);
    printf("Enter elements of matrix (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                count++;
        }
    }
    if (count > (rows * cols) / 2) {
        printf("\nMatrix is a Sparse Matrix.\n");

        // First row of tuple contains: total_rows, total_cols, non_zero_count
        int k = 1; // Index for sparse tuple
        sparse[0][0] = rows;
        sparse[0][1] = cols;
        sparse[0][2] = (rows * cols) - count;

        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    sparse[k][0] = i;
                    sparse[k][1] = j;
                    sparse[k][2] = matrix[i][j];
                    k++;
                }
            }
        }

        // 3-tuple representation
        printf("\n3-Tuple Representation:\n");
        printf("Row Col Value\n");
        for (i = 0; i < k; i++) {
            printf("%3d %3d %5d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
        }

    } else {
        printf("\nMatrix is NOT a Sparse Matrix.\n");
    }

    return 0;
}



/*SAMPLE OUTPUT
Enter number of rows and columns: 3 3
Enter elements of matrix (3 x 3):
0 0 3
0 0 0
4 0 0

Matrix is a Sparse Matrix.

3-Tuple Representation:
Row Col Value
  3   3     2
  0   2     3
  2   0     4
*/