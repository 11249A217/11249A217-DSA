Aim:
To place each item into the bin that leaves the least remaining unused space, thereby utilizing 
bin capacity as efficiently as possible and minimizing the number of bins used.

Algorithm 
• For each item, iterate through all existing bins. 
• Place the item in the bin that has enough capacity and results in the minimum remaining empty 
space (the "tightest" fit). 
• If no bin can accommodate the item, open a new bin. 

Program:
1. #include <stdio.h> 
2. void bestFit(int items[], int n, int capacity) 
3. { 
4.     printf("\nBest Fit Algorithm\n"); 
5.  
6.     int bin[n]; 
7.     int binCount = 0; 
8.  
9.     // Initialize bins with full capacity 
10.     for (int i = 0; i < n; i++) 
11.         bin[i] = capacity; 
12.  
13.     // Process each item 
14.     for (int i = 0; i < n; i++) 
15.     { 
16.         int bestIndex = -1; 
17.         int minSpace = capacity + 1; 
18.  
19.         // Find bin with least remaining space after placement 
20.         for (int j = 0; j < binCount; j++) 
21.         { 
22.             if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
23.             { 
24.                 bestIndex = j; 
25.                 minSpace = bin[j] - items[i]; 
26.             } 
27.         } 
28.  
29.         // Identified the best bin for the current item 
30.         if (bestIndex != -1) 
31.         { 
32.             bin[bestIndex] -= items[i]; 
33.             printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], 
bestIndex + 1); 
34.         } 
35.         else // New bin needed 
36.         { 
37.             bin[binCount++] -= items[i]; 
38.             printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], 
binCount); 
39.         } 
40.     } 
41.     printf("Total bins used = %d\n", binCount); 
42. } 
43.  
44. int main()
45. { 
46.     int n, capacity; 
47.  
48.     printf("Enter number of items: "); 
49.     scanf("%d", &n); 
50.  
51.     /* Define an array to hold item sizes 
52.     1. Only after we know the number of items or 
53.     2. Define a large array and waste memory or 
54.     3. Use dynamic allocation 
55.     if this is not taken care then random values will be in the array */ 
56.     int items[n]; 
57.  
58.     printf("Enter bin capacity: "); 
59.     scanf("%d", &capacity); // FIXED: %d instead of %f 
60.  
61.     printf("Enter item sizes:\n"); 
62.     for (int i = 0; i < n; i++) 
63.     { 
64.         int itemSize; 
65.         printf("Item %d: ", i + 1); 
66.         scanf("%d", &itemSize); 
67.  
68.         if (itemSize <= capacity) 
69.         { 
70.             items[i] = itemSize; 
71.         } 
72.         else 
73.         { 
74.             printf("Item size exceeds bin capacity. Please enter a valid 
size.\n"); 
75.             i--; 
76.         } 
77.     } 
78.     bestFit(items, n, capacity); 
79.     return 0; 
80. }
