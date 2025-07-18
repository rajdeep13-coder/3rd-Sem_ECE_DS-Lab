#include <stdio.h>
int main() {
    int arr[100];       
    int n, i, posi, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position to insert (1 to %d): ", n+1);
    scanf("%d", &posi);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (i = n; i >= posi; i--) {
        arr[i] = arr[i - 1];
    }
    arr[posi - 1] = val;
    n++; 
    printf("Updated array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
