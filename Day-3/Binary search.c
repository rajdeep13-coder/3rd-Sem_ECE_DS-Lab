#include <stdio.h>
int main() {
    int a[100], n, i, key, low, high, mid, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (!found)
        printf("Element not found.\n");

    return 0;
}
