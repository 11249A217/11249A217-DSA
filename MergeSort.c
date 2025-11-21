Aim:

To sort a given list of elements in ascending order using the Merge Sort technique in C.

Algorithm (Merge Sort):
1. Main Merge Sort Algorithm

Start

If the array has more than one element:

Find the middle index mid = (low + high) / 2

Recursively divide the array into two halves:

Left half: low to mid

Right half: mid+1 to high

Merge the two sorted halves.

Stop

2. Merge Procedure

Start

Create two temporary arrays:

L[] for left subarray

R[] for right subarray

Copy data into temporary arrays.

Initialize pointers i = 0, j = 0, and k = low.

While both subarrays have elements:

If L[i] <= R[j], place L[i] into the main array and increment i.

Else, place R[j] into the main array and increment j.

Copy any remaining elements of L[] or R[].

Stop

Program:

#include <stdio.h>

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    // Merge logic
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy left-out elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy temp back to original
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);      // Left part
        mergeSort(arr, mid + 1, right); // Right part
        merge(arr, left, mid, right);   // Merge halves
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
