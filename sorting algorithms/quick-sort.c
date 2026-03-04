#include <stdio.h>
int main() {
    int arr[100], n;
    int stack_low[100], stack_high[100];   // manual recursion stack
    int top = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    // Push initial range
    stack_low[++top] = 0;
    stack_high[top] = n - 1;
    while(top >= 0) {
        int low = stack_low[top];
        int high = stack_high[top--];
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j < high; j++) {
            if(arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        // Push left part
        if(pi - 1 > low) {
            stack_low[++top] = low;
            stack_high[top] = pi - 1;
        }
        // Push right part
        if(pi + 1 < high) {
            stack_low[++top] = pi + 1;
            stack_high[top] = high;
        }
    }
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
