First fit:
Aim:
To implement the First Fit algorithm in the Bin Packing Problem.

Algorithm:
First Fit (FF): 
1. For each item, iterate through existing bins. 
2. Place the item in the first bin that has enough remaining capacity. 
3. If no such bin exists, open a new bin and place the item there. 

Program:
1. #include <stdio.h> 
2. 
3. void firstFit(int items[], int n, int capacity) 
4. { 
5.     int bin[n];       // Available capacity of bins 
6.     int binCount = 0; // Number of bins used / active bins 
7.  
8.     // Initialize all bins with full capacity 
9.     for (int i = 0; i < n; i++) 
10.         bin[i] = capacity; 
11.  
12.     // Process each item 
13.     for (int i = 0; i < n; i++) 
14.     { 
15.         int placed = 0; // flag to check if item is placed 
16.  
17.         // Check existing bins 
18.         for (int j = 0; j < binCount; j++) 
19.         { 
20.             // items fits in the current bin 
21.             if (bin[j] >= items[i]) 
22.             { 
23.                 bin[j] -= items[i]; // Reduce bin capacity by item size 
24.                 printf("Item %d placed in Bin %d\n", items[i], j + 1); 
25.                 placed = 1; 
26.                 break; // First Fit: stop at first match 
27.             } 
28.         } 
29.         // Create new bin if item is not fitted in any existing bin 
30.         if (!placed) 
31.         { 
32.             bin[binCount] -= items[i]; 
33.             printf("Item %d placed in Bin %d\n", items[i], binCount + 1); 
34.             binCount++; 
35.         } 
36.     } 
37.     printf("Total bins used = %d\n", binCount);
38. } 
39.  
40. int main() 
41. { 
42.     int n, capacity; 
43.     printf("Enter number of items: "); 
44.     scanf("%d", &n); 
45.  
46.     printf("Enter bin capacity: "); 
47.     scanf("%d", &capacity); 
48.     int items[n]; 
49.  
50.     printf("Enter item sizes:\n"); 
51.     for (int i = 0; i < n; i++) 
52.     { 
53.         int itemSize; 
54.         printf("Item %d: ", i + 1); 
55.         scanf("%d", &itemSize); 
56.  
57.         if (itemSize <= capacity) 
58.         { 
59.             items[i] = itemSize; 
60.         } 
61.         else 
62.         { 
63.             printf("Item size exceeds bin capacity. Please enter a valid 
size.\n"); 
64.             i--; 
65.         } 
66.     } 
67.  
68.     firstFit(items, n, capacity); 
69.     return 0; 
70. }
