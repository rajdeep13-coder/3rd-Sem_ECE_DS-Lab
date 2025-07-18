#include <stdio.h>
int main() {
    int a[10][10], b[100], r, c, i, j, k = 0;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            b[k++] = a[i][j];
    printf("1D array:\n");
    for (i = 0; i < r * c; i++)
        printf("%d ", b[i]);
    return 0;
}
