#include <stdio.h>

int main() {
    int a[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int stack[100], top = -1;
    stack[++top] = 0;
    stack[++top] = n - 1;
    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];
        int pivot = a[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (a[j] <= pivot) {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int p = i + 1; 

        printf("Pivot placed at index %d: ", p);
        for (int k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
