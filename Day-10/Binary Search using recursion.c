#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) 
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target)
        return mid; 
    else if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);  
    else
        return binarySearch(arr, mid + 1, right, target); 
}
int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}
