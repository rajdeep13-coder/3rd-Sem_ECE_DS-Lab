#include <stdio.h>

// Function to find maximum number
int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

// Counting sort for digits
void countSort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    // Count occurrences
    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count array
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array
    for(int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy back to original array
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for(int exp = 1; max/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    radixSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}