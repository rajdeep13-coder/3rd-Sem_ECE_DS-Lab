#include <stdio.h>
int main() {
    int a[10][10], r, c, i, j, flag = 1;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    if (r != c) {
        printf("Matrix is not square, so cannot be upper triangular.\n");
        return 0;
    }
    printf("Enter elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    for (i = 1; i < r; i++)
        for (j = 0; j < i; j++)
            if (a[i][j] != 0)
                flag = 0;
    if (flag)
        printf("Matrix is upper triangular.\n");
    else
        printf("Matrix is not upper triangular.\n");

    return 0;
}
