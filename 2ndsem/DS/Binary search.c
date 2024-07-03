#include <stdio.h>
// Recursive Binary Search function
int binarySearch(int arr[], int low, int high, int key) {
if (high >= low) {
int mid = low + (high - low) / 2;
// If the key is present at the middle itself
if (arr[mid] == key)
return mid;
// If the key is smaller than the middle element, it must be in the left subarray
if (arr[mid] > key)

return binarySearch(arr, low, mid - 1, key);
// If the key is larger than the middle element, it must be in the right subarray
return binarySearch(arr, mid + 1, high, key);
}
// The key was not found
return -1;
}
int main(void) {
int arr[] = {1, 2, 3, 4, 5};
int key = 3;
int n = sizeof(arr) / sizeof(arr[0]);
int result = binarySearch(arr, 0, n - 1, key);
if (result == -1)
printf("Key not found\n");
else
printf("Key found at index %d\n", result);
return 0;
}
