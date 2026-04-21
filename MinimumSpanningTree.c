Aim:
Prim’s Algorithm is used to find a Minimum Spanning Tree (MST) of a connected, weighted, undirected graph
  
Prim's Algorithm:
1. Start with any vertex  
2. Mark it as visited  
3. Look at all edges from visited vertices  
4. Consider only edges going to unvisited vertices  
5. Pick the smallest (minimum weight) edge  
6. Add that edge and the new vertex to the tree  
7. Repeat steps 3–6  
8. Continue until all vertices are included

Program:
#include <stdio.h> 
#include <stdlib.h> 
#define V 5 // Number of vertices 
 
// Function to find the vertex with minimum key value (Minimum edge weight) 
int minKey(int key[], int visited[]) 
{ 
    int min = 999999; // Initialize min to a large value 
    int min_index = 0; // Initialize min_index to 0 as it starts with vertex 0 
 
    for (int i = 0; i < V; i++) 
    { 
        if (!visited[i] && key[i] < min) 
        { 
            min = key[i]; 
            min_index = i; 
        } 
    } 
    return min_index; 
} 
 
// Function to print MST 
void printPrimMST(int parent[], int graph[V][V]) 
{ 
    printf("\nPrim's MST:\n"); 
    printf("Edge \tWeight\n"); 
 
    int total = 0; 
    for (int i = 1; i < V; i++) 
    { 
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
        total += graph[i][parent[i]];
  } 
    printf("Total Cost = %d\n", total); 
} 
 
// Prim's Algorithm Implementation 
void primMST(int graph[V][V]) 
{ 
    int parent[V];  // Stores MST 
    int key[V];     // Minimum edge weight 
    int visited[V]; // Track visited vertices 
 
    // Step 1: Initialize 
    for (int i = 0; i < V; i++) 
    { 
        key[i] = 999999; 
        visited[i] = 0; 
    } 
 
    // Step 2: Start from vertex 0 
    key[0] = 0; 
    parent[0] = -1; 
 
    // Step 3: Build MST 
    for (int count = 0; count < V - 1; count++) 
    { 
        // Pick minimum key vertex 
        int u = minKey(key, visited); 
        visited[u] = 1; 
 
        // Update adjacent vertices for the picked vertex u 
        for (int v = 0; v < V; v++) 
        { 
            //(u, v) is an edge and v is not visited and weight of (u, v) is smaller 
than key[v] 
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) 
 { 
                parent[v] = u; 
                key[v] = graph[u][v]; 
            } 
        } 
    } 
    printPrimMST(parent, graph); 
} 
 
int main() 
{ 
    // Graph for Prim's (Adjacency Matrix) 
    int graph[V][V] = { 
        {0, 2, 3, 0, 0}, 
        {2, 0, 5, 3, 0}, 
        {3, 5, 0, 0, 4}, 
        {0, 3, 0, 0, 2}, 
        {0, 0, 4, 2, 0}}; 
 
    // Run Prim's Algorithm 
    primMST(graph); 
    return 0; 
}
Aim of Kruskal’s Algorithm:

Kruskal’s Algorithm is used to find a Minimum Spanning Tree (MST) of a connected, weighted, undirected graph.

Kruskal’s Algorithm 
1. List all edges of the graph  
2. Sort edges in increasing order of weight  
3. Pick the smallest edge  
4. Add it to the tree  
5. Pick the next smallest edge  
6. Add it only if it does NOT form a cycle  
7. Repeat until (V − 1) edges are selected  

Program:
#include <stdio.h> 
#define V 5 
#define E 6 
int parent[V]; 
 
// Find the representative (leader) of the set containing vertex v 
int findLeader(int v) 
{ 
    while (parent[v] != v) 
        v = parent[v]; 
    return v; 
} 
 
// Merge two disjoint sets 
void mergeSets(int u, int v) 
{ 
    int a = findLeader(u); 
    int b = findLeader(v); 
    parent[a] = b; 
} 
 
// Bubble sort to organize edges by weight 
void sortEdges(int edges[E][3]) 
{ 
    for (int i = 0; i < E - 1; i++) 
    { 
        for (int j = 0; j < E - i - 1; j++) 
        { 
            if (edges[j][2] > edges[j + 1][2])
               { 
                for (int k = 0; k < 3; k++) 
                { 
                    int temp = edges[j][k]; 
                    edges[j][k] = edges[j + 1][k]; 
                    edges[j + 1][k] = temp; 
                } 
            } 
        } 
    } 
} 
 
void kruskal(int edges[E][3]) 
{ 
    sortEdges(edges); 
    for (int i = 0; i < V; i++) 
        parent[i] = i; 
 
    int count = 0, cost = 0; 
    printf("Selected Edges:\n"); 
 
    for (int i = 0; i < E; i++) 
    { 
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        int w = edges[i][2]; 
 
        // If leaders are different, no cycle is formed 
        if (findLeader(u) != findLeader(v)) 
        { 
            printf("%d -- %d (Weight: %d)\n", u, v, w); 
            mergeSets(u, v); 
            cost += w; 
            count++; 
        }
  if (count == V - 1) 
            break; 
    } 
    printf("Total Cost: %d\n", cost); 
} 
 
int main() 
{ 
    int edges[E][3] = { 
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5}, {1, 3, 3}, {2, 4, 4}, {3, 4, 2}}; 
 
    kruskal(edges); 
    return 0; 
} 
