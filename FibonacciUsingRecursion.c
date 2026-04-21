Aim:
To write a program to find the Fibonacci term using recursion.

Algorithm :
1. Read the input n and validate that it is non-negative 
2. If n ≤ 1, return n (base condition) 
3. Otherwise, return F(n) = F(n−1) + F(n−2)  Recursive function call 
4. Display the returned value as the nth Fibonacci term 

Program:
1. #include <stdio.h> 
2.  
3. /** 
4.  * Function: fib 
5.  * Description: Computes the nth Fibonacci term using a recursive approach. 
6.  * Complexity: O(2^n) - Tree Recursion with overlapping subproblems. 
7.  * * @param n: The index of the Fibonacci term to be computed. 
8.  * @return: The Fibonacci value at the given index. 
9.  */ 
10. int fib(int n) 
11. { 
12.     /* Base Condition: If n is 0 or 1, the term is the value itself[cite: 141]. 
*/ 
13.     if (n <= 1) 
14.     { 
15.         return n; 
16.     } 
17.  
18.     /* * Recursive Step: F(n) = F(n-1) + F(n-2)[cite: 142]. 
19.      * Note: This causes the function to branch twice for every call, 
20.      * leading to the exponential time complexity observed in DAA. 
21.      */ 
22.     return fib(n - 1) + fib(n - 2); 
23. } 
24.  
25. int main() 
26. { 
27.     int n, result = 0; 
28.     /* Step 1: Read the input n and validate that it is non-negative[cite: 140]. 
*/ 
29.     printf("Enter the value of n: "); 
30.     scanf("%d", &n); 
31.  
32.     /* Checking if input is a valid integer and non-negative. */ 
33.     if (n != 1 || n < 0) 
34.     { 
35.         printf("Invalid input\n"); 
36.         return 1; 
37.     } 
38.     printf("\nNth Fibonacci term = %d\n", fib(n)); 
39.     return 0; 
40. }
