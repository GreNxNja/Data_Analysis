#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to find the vertex with the minimum key value,
// which is not yet included in the MST
int minKey(int key[], bool mstSet[], int vertices)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[][MAX_VERTICES], int vertices)
{
    printf("Edge   Weight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[][MAX_VERTICES], int vertices)
{
    int parent[MAX_VERTICES];  // Array to store the constructed MST
    int key[MAX_VERTICES];     // Key values used to pick minimum weight edge in cut
    bool mstSet[MAX_VERTICES]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < vertices - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, vertices);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++)
        {
            // Update key[v] only if the current weight is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, vertices);
}

int main()
{
    int vertices;

    // Get the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    // Get the adjacency matrix representing the graph
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    // Print the Minimum Spanning Tree (MST) using Prim's algorithm
    printf("Minimum Spanning Tree using Prim's algorithm:\n");
    primMST(graph, vertices);

    return 0;
}
