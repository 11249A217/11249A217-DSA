Aim:
To design an algorithm that uses randomness as part of its logic to achieve good expected performance, 
simplicity, or probabilistic guarantees on correctness or efficiency.

Algorithm(without randomization):
1. Choose the last element of the current sub-array as the Pivot. 
2. Move all elements smaller than the pivot to its left and all larger elements to its right. 
3. Repeat Step 1 & Step 2 for the left and right sub-arrays independently. 
4. If the sub-array has 1 or 0 elements then it is already sorted; STOP.

 Algorithm (With Randomization) 
1. Pick a random index k between the current low and high boundaries. 
2. Swap the element at index k with the element at the high index. 
3. Choose the last element ("randomly placed") of the current sub-array as the pivot. 
4. Move all elements smaller than the pivot to its left and all larger elements to its right. 
5. Repeat Step 1 & Step 4 for the left and right sub-arrays independently. 
6. If the sub-array has 1 or 0 elements then it is already sorted; STOP. 

Program:
1. #include <stdio.h> 
2. #include <stdlib.h> 
3. #include <time.h> 
4.  
5. // Simple swap function to exchange two integers 
6. void swap(int *a, int *b) 
7. { 
8.     int temp = *a; 
9.     *a = *b; 
10.     *b = temp; 
11. } 
12.  
13. // Standard Partitioning logic 
14. int partition(int arr[], int low, int high) 
15. { 
16.     int pivot = arr[high]; 
17.     int i = (low - 1); 
18.  
19.     for (int j = low; j < high; j++) 
20.     { 
21.         if (arr[j] < pivot) 
22.         { 
23.             i++; 
24.             swap(&arr[i], &arr[j]);
25.         } 
26.     } 
27.     swap(&arr[i + 1], &arr[high]); 
28.     return (i + 1); 
29. } 
30.  
31. void quickSort(int arr[], int low, int high) 
32. { 
33.     if (low < high) 
34.     { 
35.         // Pick a random index and swap it with the last element (high element) 
36.         int randomIndex = low + rand() % (high - low + 1); 
37.         swap(&arr[randomIndex], &arr[high]); 
38.  
39.         // Now partition using that swapped random element as the pivot 
40.         int pi = partition(arr, low, high); 
41.  
42.         // Recursively sort the halves 
43.         quickSort(arr, low, pi - 1); 
44.         quickSort(arr, pi + 1, high); 
45.     } 
46. } 
47.  
48. int main() 
49. { 
50.     int n; 
51.     srand(time(NULL)); // Initialize random seed 
52.  
53.     printf("Enter number of elements: "); 
54.     if (scanf("%d", &n) != 1 || n <= 0) 
55.     { 
56.         printf("Invalid input. Please enter a positive integer.\n"); 
57.         return 1; 
58.     } 
59.  
60.     int numbersToSort[n]; 
61.     printf("Enter %d integers: ", n); 
62.     for (int i = 0; i < n; i++) 
63.         scanf("%d", &numbersToSort[i]); 
64.  
65.     // Call the randomized quicksort function 
66.     quickSort(numbersToSort, 0, n - 1); 
67.  
68.     printf("\nSorted array: "); 
69.     for (int i = 0; i < n; i++) 
70.         printf("%d ", numbersToSort[i]); 
71.  
72.    return 0; 
73. } 
