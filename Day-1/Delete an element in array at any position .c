#include <stdio.h>
int main() {
    int a[100], n, i, p;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &p);
    for (i = p - 1; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;
    printf("Updated array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
