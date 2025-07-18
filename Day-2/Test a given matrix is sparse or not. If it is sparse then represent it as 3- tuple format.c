#include <stdio.h>

int main() {
    int a[10][10], r, c, i, j, count = 0, k = 1;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                count++;
        }

    if (count > (r * c) / 2) {
        printf("It is a sparse matrix.\n");         //checking

        int tuple[100][3];                 // 3-tuple format
        tuple[0][0] = r;
        tuple[0][1] = c;
        tuple[0][2] = (r * c) - count;

        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (a[i][j] != 0) {
                    tuple[k][0] = i;
                    tuple[k][1] = j;
                    tuple[k][2] = a[i][j];
                    k++;
                }
            }
        }

        printf("3-Tuple representation:\n");
        for (i = 0; i < k; i++) {
            printf("%d %d %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
        }
    } else {
        printf("It is not a sparse matrix.\n");
    }

    return 0;
}
