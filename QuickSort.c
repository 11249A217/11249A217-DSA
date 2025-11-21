Aim:

To sort a given list of elements in ascending order using the Quick Sort technique in C.

Algorithm (Quick Sort):
Step 1: Partition Algorithm

Start

Choose a pivot element (usually the first or last element).

Set low and high positions.

While low < high:

While arr[low] <= pivot move low to the right.

While arr[high] > pivot move high to the left.

If low < high, swap arr[low] and arr[high].

Swap the pivot element with arr[high].

Return the pivot position.

Step 2: Quick Sort Algorithm

Start

If low < high:

Call Partition and get pivot position p.

Recursively apply Quick Sort to:

Left subarray → low to p - 1

Right subarray → p + 1 to high

Stop

Program:

#include <stdio.h>

//Swap the numbers / Call by referene to persist changes
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition 
int partition(int list[], int low, int high)
{
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    quickSort(list, 0, n - 1);

    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}
