Aim:
To compute the shortest path distances from a source vertex to all other vertices in a weighted graph
with non-negative edge weights, minimizing the total cost of travel.

  Algorithm :
1. Initialize a dist array where dist[source] = 0 and all others are ∞. 
2. Maintain a set of unvisited vertices. 
3. While there are unvisited vertices: 
o Select the vertex u with the minimum dist[u]. 
o For each neighbor v of u:  
▪ If dist[u] + weight(u, v) < dist[v]:  
▪ Update dist[v] (Relaxation). 
4. Mark u as visited.

Program:
1. #include <stdio.h> 
2. #define V 5 
3. #define INF 999999 
4.  
5. /* Mimics the 'Dequeue' operation by finding the min distance among unvisited 
nodes */ 
6. int extractMin(int dist[], int visited[]) 
7. { 
8. int min = INF, min_index = -1; 
9. for (int v = 0; v < V; v++) 
10. { 
11. if (!visited[v] && dist[v] <= min) 
12. {
13. min = dist[v]; 
14. min_index = v; 
15. } 
16. } 
17. return min_index; 
18. } 
19.  
20. void dijkstra(int graph[V][V]) 
21. { 
22. int dist[V], visited[V]; // Visited array acts as a "queue" to track which 
vertices are still to be processed 
23.  
24. /** 
25. Initialization all with distance infinity 
26. Adding Vertex to the "queue" and marking them as unvisited (0) 
27. */ 
28.  
29. for (int i = 0; i < V; i++) 
30. { 
31. dist[i] = INF; 
32. visited[i] = 0; // 0 means vertex is still "in the queue" 
33. } 
34.  
35. dist[0] = 0; // Consider the source vertex as 0 and set its distance to 0 
36.  
37. for (int count = 0; count < V; count++) 
38. { 
39. int u = extractMin(dist, visited); /* Indentify & Dequeue the vertex u with the 
minimum distance */ 
40. if (u == -1) 
41. break; 
42.  
43. visited[u] = 1; // Mark extracted u as visited (no longer in the "queue") 
44.  
45. /* For each vertex j adjacent to u, check for relaxation of the edge (u, j) */ 
46. for (int j = 0; j < V; j++) 
47. { 
48. if (graph[u][j] > 0 && !visited[j]) 
49. { 
50. if (dist[j] > dist[u] + graph[u][j]) 
51. { 
52. dist[j] = dist[u] + graph[u][j]; /* Relaxation */ 
53. } 
54. } 
55. } 
56. } 
57. 
58. printf("\nVertex \t Distance from Source (0)\n"); 
59. for (int i = 0; i < V; i++) 
60. printf("%d --> %d\n", i, dist[i]); 
61. } 
62.  
63. int main() 
64. { 
65. int graph[V][V] = { 
66. {0, 10, 0, 30, 100}, 
67. {10, 0, 50, 0, 0}, 
68. {0, 50, 0, 20, 10}, 
69. {30, 0, 20, 0, 60}, 
70. {100, 0, 10, 60, 0}}; 
71.  
72. dijkstra(graph); 
73. return 0; 
74. }   
