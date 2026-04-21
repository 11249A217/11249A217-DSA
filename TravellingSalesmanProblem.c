Aim:
To implement the solution for the Travelling Salesman Problem.

Algorithm:
1. For every city i and subset of cities S, define Cost(i, S) as the minimum distance starting at city 1, 
visiting all cities in S, and ending at city i. 
2. Use the recurrence: Cost(i, S) = min{ Cost(j, S - {i}) + dist(j, i)} for all j in S.  
3. Solve subproblems of increasing size until all cities are included. 
4. Add the distance back to the starting city to complete the cycle. 

Program:
1. #include <stdio.h> 
2. #define MAXN 15 
3.  
4. // Used to initialize minCost to a very large value. 
5. // Since all travel costs are non-negative, any valid cost 
6. // will be less than INF and replace it. 
7. #define INF 999999 
8.  
9. int n; 
10. int d[MAXN][MAXN]; 
11. // Bitwise AND checks whether that city's bit is set in S. 
12. // S will have 2^n possible combinatios of cities, so the size of it should be 
2^MAXN that 1<< MAXN
13. int dp[MAXN][1 << MAXN]; 
14.  
15. // g(i,S) 
16. // Returns the minimum cost of visiting all cities in set S starting from city i 
17. int g(int i, int S) 
18. { 
19.     // Base case: If S is empty, return the cost to return to the starting city 
(A) 
20.     if (S == 0) 
21.         return d[i][0]; //g(i,{}) = d[i][0] - Cost to return to starting city A 
from city i 
22.  
23.     //If the g(i,S) has already been computed, return the stored value 
24.     if (dp[i][S] != -1)  
25.         return dp[i][S]; 
26.  
27.     int minCost = INF; 
28.  
29.     // You can also start the loop from k = 1 to < n, since city 0 (A) is not 
included in S. 
30.     // Even if you start from k = 0, the condition S & (1 << k) will be false, so 
it won't affect the result. 
31.     for (int k = 0; k < n; k++) 
32.     { 
33.         // (1 << k) creates a mask for city k. 
34.         // Bitwise AND checks whether that city's bit is set in S.  
35.         // If the result is non-zero, it means city k is included in S. 
36.         if (S & (1 << k)) 
37.         { 
38.             // g(i, S) = d(i,k) + g(k, S & ~(1 << k)) 
39.             int cost = d[i][k] + g(k, S & ~(1 << k)); 
40.  
41.             //If the calculated cost is less than the current minimum cost, 
update minCost 
42.             if (cost < minCost)
  43.             { 
44.                 minCost = cost; 
45.             } 
46.         } 
47.     } 
48.     // Store the computed final minimum cost in dp[i][S] for current city i to 
cities in S before returning it 
49.     return dp[i][S] = minCost; 
50. } 
51.  
52. int main() 
53. { 
54.     printf("Enter number of cities: "); 
55.     scanf("%d", &n); 
56.  
57.     printf("Enter cost matrix:\n"); 
58.     for (int i = 0; i < n; i++) 
59.         for (int j = 0; j < n; j++) 
60.             scanf("%d", &d[i][j]); 
61.  
62.     // -1 - Indicates that the value has not been computed yet 
63.     // Since all valid TSP costs are non-negative, -1 safely indicates 
"uncomputed". 
64.     for (int i = 0; i < n; i++) 
65.         for (int mask = 0; mask < (1 << n); mask++) 
66.         { 
67.             dp[i][mask] = -1; 
68.         } 
69.  
70.     int S = 0; 
71.     for (int i = 1; i < n; i++) 
72.         S |= (1 << i); 
73.  
74.     int result = g(0, S);
76.     printf("Given Cost Matrix\n"); 
77.     for (int i = 0; i < n; i++) 
78.     { 
79.          
80.         printf("|"); 
81.         for (int j = 0; j < n; j++) 
82.             printf(" %d ", d[i][j]); 
83.         printf("|\n"); 
84.     } 
85.     printf("Minimum travelling cost: %d\n", result); 
86.  
87.     return 0; 
88. }
