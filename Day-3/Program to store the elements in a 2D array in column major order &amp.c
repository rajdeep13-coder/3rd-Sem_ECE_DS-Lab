#include <stdio.h>
int main() {
    int a[10][10], r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements in column-major order:\n");
    for (j = 0; j < c; j++)
        for (i = 0; i < r; i++)
            scanf("%d", &a[i][j]);
    printf("Matrix (row-wise display):\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
