#include <stdio.h>
#include <stdbool.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 100

// Function to perform Depth-First Search (DFS) on the graph
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex, bool visited[])
{
    printf("%d ", startVertex);
    visited[startVertex] = true;

    for (int i = 0; i < vertices; i++)
    {
        if (graph[startVertex][i] == 1 && !visited[i])
        {
            dfs(graph, vertices, i, visited);
        }
    }
}

int main()
{
    int vertices, startVertex;

    // Get the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    // Get the adjacency matrix representing the graph
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    // Get the starting vertex for DFS
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Initialize visited array
    bool visited[MAX_VERTICES] = {false};

    // Perform DFS
    printf("Depth-First Search starting from vertex %d:\n", startVertex);
    dfs(graph, vertices, startVertex, visited);

    return 0;
}
