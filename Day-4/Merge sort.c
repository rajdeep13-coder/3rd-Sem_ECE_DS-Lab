#include <stdio.h>
int main() {
    int a[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int temp[100];
    for (int size = 1; size < n; size *= 2) {
        for (int l = 0; l < n; l += 2 * size) {
            int m = l + size - 1;
            int r = l + 2 * size - 1;
            if (m >= n) m = n - 1;
            if (r >= n) r = n - 1;

            int i = l, j = m + 1, k = l;
            while (i <= m && j <= r) {
                if (a[i] <= a[j]) temp[k++] = a[i++];
                else temp[k++] = a[j++];
            }
            while (i <= m) temp[k++] = a[i++];
            while (j <= r) temp[k++] = a[j++];
            for (i = l; i <= r; i++) {
                a[i] = temp[i];
            }
        }
    }
    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
