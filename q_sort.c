#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksortMiddle(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[(low + high) / 2]; // Selecting the middle element as the pivot
        int i = low;
        int j = high;
        int temp;

        while (i <= j) {
            while (arr[i] < pivot) i++; // Moving elements smaller than pivot to the left
            while (arr[j] > pivot) j--; // Moving elements greater than pivot to the right

            if (i <= j) {
                temp = arr[i];         // Swapping elements
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        // Recursively sort the two partitions
        if (low < j) quicksortMiddle(arr, low, j);
        if (i < high) quicksortMiddle(arr, i, high);
    }
}

// Utility function to print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int array1[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(array1) / sizeof(array1[0]);

    printf("Original Array: \n");
    printArray(array1, n);

    // Using the Middle Element as Pivot
    quicksortMiddle(array1, 0, n - 1);
    printf("Sorted with Middle Element as Pivot: \n");
    printArray(array1, n);

    return 0;
}
