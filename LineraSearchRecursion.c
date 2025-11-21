AIM

To write a program to search for a given element in an array using Linear Search implemented with recursion, and to determine whether the element is present and at which index it occurs.

ALGORITHM (Linear Search using Recursion)

Step 1: Start.

Step 2: Define a recursive function linearSearch(arr, n, key, index)

arr → the array

n → size of the array

key → element to search

index → current index to check

Step 3: If index >= n, return -1 (element not found).

Step 4: If arr[index] == key, return index (element found).

Step 5: Otherwise, recursively call
linearSearch(arr, n, key, index + 1).

Step 6: Return the result of the recursive call.

Step 7: Stop.

Program:
#include <stdio.h>
#include <stdbool.h>

int LinearSearch(int dataSet[], int size, int elementToFind, int index)
{
    if (index >= size)
    {
        return -1;
    }
    if (dataSet[index] == elementToFind)
    {
        return index;
    }
    return LinearSearch(dataSet, size, elementToFind, index + 1);
}
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d", &size);

    int searchSpace[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter the %d out of %d element in data set: ", i + 1, size);
        scanf("%d", &searchSpace[i]);
    }

    printf("Given Dataset for Linear Search is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d - ", searchSpace[i]);
    }

    printf("\nEnter the element to find in the dataset: ");
    scanf("%d", &elementToFind);

    int foundAt = LinearSearch(searchSpace, size, elementToFind, i = 0);

    if (foundAt >= 0)
        printf("Required element %d is found in the dataset at position %d or index %d", elementToFind, foundAt + 1, foundAt);
    else
        printf("Required element %d is NOT found in the dataset!!!", elementToFind);
}
