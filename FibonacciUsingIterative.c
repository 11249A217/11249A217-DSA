Aim:
To write a program to find the Fibonacci term using an iterative method.

Algorithm:
1. Read the value of n and validate n ≥ 0. 
2. Handle Base Cases: 
 If n = 0, display 0 and stop. 
 If n ≥ 1, display 0, 1. 
3. Initialize a = 0 and b = 1. 
4. Repeat for i from 2 to n: 
 Compute NextTerm = a + b. 
 Display NextTerm (to satisfy the "Series" requirement). 
 Update a = b and b = NextTerm. 
5. Identify b as the nth Fibonacci term. 

Program:
1. #include <stdio.h> 
2.  
3. int main() 
4. { 
5.     int n; 
6.     int a = 0, b = 1, c; 
7.  
8.     printf("Enter the number of terms (n): "); 
9.     if (scanf("%d", &n) != 1 || n <= 0) 
10.     { 
11.         printf("Invalid input. Please enter a positive integer.\n"); 
12.         return 0; 
13.     } 
14.  
15.     printf("Fibonacci Series: "); 
16.  
17.     // Handle 1st term 
18.     if (n >= 1) 
19.         printf("%d ", a); 
20.  
21.     // Handle 2nd term 
22.     if (n >= 2) 
23.         printf("%d ", b); 
24.     // Iterative computation from 3rd term onwards 
25.     for (int i = 3; i <= n; i++) 
26.     { 
27.         c = a + b; 
28.         printf("%d ", c); 
29.         a = b; 
30.         b = c; 
31.     } 
32.  
33.     /* Logic Fix: If n is 1, the nth term is 'a' (0). 
34.        Otherwise, the nth term is 'b'. 
35.     */ 
36.     if (n == 1) 
37.         printf("\nFibonacci term %d = %d\n", n, a); 
38.     else 
39.         printf("\nFibonacci term %d = %d\n", n, b); 
40.  
41.     return 0; 
42. } 
