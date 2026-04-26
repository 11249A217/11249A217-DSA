Aim:
To find a near-optimal solution to an optimization problem within a guaranteed bound of the optimal solution,
using efficient computation when finding the exact solution is impractical.

 Algorithm (2-Approximation Greedy) 
1. Initialize a set C to be empty (this will hold our vertex cover). 
2. Mark all vertices as "not visited." 
3. Iterate through every edge (u, v) in the graph: 
4. If neither u nor v is already in the set C (both are unvisited): 
5. Add both u and v to the set C. 
6. Mark both u and v as "visited." 
7. The set C is a vertex cover that is at most twice the size of the optimal cover. 

Program:
1. #include <stdio.h> 
2. #define V 5 // Number of vertices in our graph 
3.  
4. /* A simple greedy approach to find a Vertex Cover. 
5.  * It follows a 2-approximation strategy. 
6.  */ 
7. void findVertexCover(int graph[V][V]) 
8. { 
9.     int visited[V]; // Array to represent our Cover Set 'C' 
10.  
11.     // Start with an empty set C by marking all vertices as "unmarked = 0" 
12.     for (int i = 0; i < V; i++) 
13.     { 
14.         visited[i] = 0; 
15.     } 
16.  
17.     // Repeat until no unmarked edges remain in C (visited array) 
18.     // We use nested loops to scan every possible edge (u, v) in the matrix. 
19.     for (int u = 0; u < V; u++) 
20.     { 
21.         for (int v = 0; v < V; v++) 
22.         { 
23.  
24.             // graph[u][v] == 1 --> Edge Exists 
25.             // !visited[u] && !visited[v] --> Both endpoints are unmarked. 
26.             if (graph[u][v] == 1 && !visited[u] && !visited[v]) 
27.             { 
28.                 // Add BOTH its endpoints to cover set C 
29.                 visited[u] = 1; 
30.                 visited[v] = 1; 
31.  
32.                 /* Removing of all edges incident on those two vertices 
33.                 We don't need to code to delete the edges.  
34.                 By marking 'u' and 'v' as visited,  
35.                 our 'if' condition above will automatically skip all other edges 
connected to them! */ 
36.             } 
37.         } 
38.     } 
39.  
40.     // Return the Cover Set C by printing all vertices we marked 
41.     printf("Approximate Vertex Cover: "); 
42.     int count = 0; 
43.     for (int i = 0; i < V; i++) 
44.     { 
45.         if (visited[i]) 
46.         { 
47.             printf("%d ", i); 
48.             count++; 
49.         } 
50.     } 
51.     printf("\nTotal vertices in the cover: %d\n", count); 
52. } 
53.  
54. int main() 
55. { 
56.     // Adjacency Matrix representation (1 = Edge exists, 0 = No edge) 
57.     int graph[V][V] = { 
58.         {0, 1, 0, 0, 0}, 
59.         {1, 0, 1, 1, 0}, 
60.         {0, 1, 0, 1, 1}, 
61.         {0, 1, 1, 0, 1}, 
62.         {0, 0, 1, 1, 0}}; 
63.  
64.     printf("Executing Vertex Cover Approximation...\n"); 
65.     findVertexCover(graph); 
66.  
67.     return 0; 
68. }
