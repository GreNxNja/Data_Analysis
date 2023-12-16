#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset
{
    int parent;
    int rank;
};

// Function to find the set of an element in the union-find
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparison function to sort edges by weight in non-decreasing order
int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to find the Minimum Spanning Tree (MST) using Kruskal's algorithm
void kruskalMST(struct Edge edges[], int V, int E)
{
    struct Edge result[V]; // Array to store the result MST
    int e = 0;             // Index variable used for the result array
    int i = 0;             // Index variable used for sorting the edges array

    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Allocate memory for creating V subsets
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Initialize V subsets with single elements
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < E)
    {
        // Pick the smallest edge, and increment the index for next iteration
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause a cycle, add it to the result MST
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the edges of the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}

int main()
{
    int V, E;

    // Get the number of vertices and edges in the graph
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];

    // Get the edges of the graph along with their weights
    printf("Enter the edges (src, dest, weight):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

    // Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm
    kruskalMST(edges, V, E);

    return 0;
}
