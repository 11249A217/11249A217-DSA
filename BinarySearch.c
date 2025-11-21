AIM

To write a C program to search for a given element in a sorted array using the Binary Search technique and determine whether the element is present and at which position it occurs.

ALGORITHM (Binary Search in C)

Step 1: Start.

Step 2: Read the size of the array and the array elements (must be in sorted order).

Step 3: Read the element (key) to be searched.

Step 4: Initialize two variables:

low = 0

high = n - 1

Step 5: Repeat the following steps while low ≤ high:

Find the middle index:
mid = (low + high) / 2

If arr[mid] == key, the element is found. Return mid.

If key < arr[mid], search in the left half by setting:
high = mid - 1

Else, search in the right half by setting:
low = mid + 1

Step 6: If the loop ends, the element is not present. Return -1.

Step 7: Stop.
Program:
#include <stdio.h>
int main()
{
    int size, targetElement, start, mid, end;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int searchSpace[size];
    for(int i=0;i<size;i++)
    {
        printf("Enter element %d of %d: ",i, size-1);
        scanf("%d",&searchSpace[i]);
    }
    printf("Enter the element to search ");
    scanf("%d",&targetElement);
    start = 0;
    end = size-1;
    while (start<=end)
    {
        mid = (start + end)/2;
        if(searchSpace[mid] == targetElement)
        {
            printf("Element found at index of %d (i.e. at position %d)", mid, mid+1);
            return 0;
        }
        else if(searchSpace[mid] < targetElement)
        {
            start = mid +1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("ELement doesn't exist in the given search set");
    
   return 0;
}
