Aim:
To implement the Fractional Knapsack problem using the greedy method.

 Algorithm 
1. Calculate the value-to-weight ratio for every item. 
2. Sort items in descending order based on this ratio.  
3. Iterate through sorted items:
  o If the item's weight fits, take the whole item.  
  o If not, take the fraction of the item that fills the remaining capacity.  
4. Return the accumulated total value.  

Program:
1. #include <stdio.h> 
2.  
3. struct Item 
4. { 
5.     int weight; 
6.     int value; 
7.     float ppw; // profit per weight ratio 
8. }; 
9.  
10. /* Function to sort items by ratio in descending order */ 
11. void sort(struct Item items[], int n) 
12. { 
13.     struct Item temp; 
14.     for (int i = 0; i < n - 1; i++) 
15.     { 
16.         for (int j = 0; j < n - i - 1; j++) 
17.         { 
18.             if (items[j].ppw < items[j + 1].ppw) 
19.             { 
20.                 temp = items[j]; 
21.                 items[j] = items[j + 1]; 
22.                 items[j + 1] = temp; 
23.             } 
24.         } 
25.     } 
26. } 
27. 
 28. int main() 
29. { 
30.     int n; 
31.     float capacity; 
32.  
33.     printf("Enter number of items: "); 
34.     scanf("%d", &n); 
35.  
36.     if (n <= 0) 
37.         return 1; 
38.     struct Item items[n]; 
39.  
40.     printf("Enter weight and value of each item:\n"); 
41.     for (int i = 0; i < n; i++) 
42.     { 
43.         printf("Item %d: ", i + 1); 
44.         scanf("%d %d", &items[i].weight, &items[i].value); 
45.         items[i].ppw = (float)items[i].value / items[i].weight; 
46.     } 
47.  
48.     printf("Enter knapsack capacity: "); 
49.     scanf("%f", &capacity); 
50.  
51.     /* Sort items by value/weight ratio */ 
52.     sort(items, n); 
53.  
54.     float totalProfit = 0.0; 
55.     for (int i = 0; i < n; i++) 
56.     { 
57.         if (capacity >= items[i].weight) 
58.         { 
59.             totalProfit += items[i].value; 
60.             capacity -= items[i].weight; 
61.         } 
62.         else 
63.         { 
64.             totalProfit += items[i].ppw * capacity; 
65.             break; 
66.         } 
67.     } 
68.     printf("Maximum profit = %.2f\n", totalProfit); 
69.     return 0; 
70. }
