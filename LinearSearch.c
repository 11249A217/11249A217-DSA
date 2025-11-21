Aim:
The aim of the Linear Search algorithm is to find the position (index) of a target element in a list or array by sequentially checking each element from the beginning to the end until the desired element is found or the list ends.

Algorithm:
Let’s assume:
• 	 is the array of elements
• 	 is the number of elements in the array
• 	 is the element to be searched
Steps:
1. 	Start from the first element of the array.
2. 	Compare the current element with .
3. 	If the current element is equal to , return its index (position).
4. 	If not, move to the next element.
5. 	Repeat steps 2–4 until the end of the array.
6. 	If  is not found after checking all elements, return  (or a message saying "Element not found").

Program:
#include <stdio.h>
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d",&size);

    int searchSpace[size];
    for(i=0; i<=size-1; i++)
    {
        printf("Enter the %d out of %d element in data set: ",i+1, size);
        scanf("%d",&searchSpace[i]);
    }

    //printf("Given Dataset for Linear Search is: ");
    for(int i=0; i<size; i++)
    {
        printf("%d - ",searchSpace[i]);
    }

    printf("\nEnter the element to find in the dataset: ");
    scanf("%d",&elementToFind);
    i =0;
    while(i<size)
    {
        if(searchSpace[i] == elementToFind)
        {
            printf("Required element %d is found in the dataset at position %d or index %d",elementToFind, i+1, i);
            return 0;
        }
        i++;
    }

    printf("Required element %d is NOT found in the dataset!!!",elementToFind);
}
