#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue
{
    int front, rear;
    int capacity;
    int *array;
};

// Function to create a new queue
struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Function to enqueue a vertex to the queue
void enqueue(struct Queue *queue, int item)
{
    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->array[queue->rear] = item;
}

// Function to dequeue a vertex from the queue
int dequeue(struct Queue *queue)
{
    int item = queue->array[queue->front];
    queue->front++;

    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;

    return item;
}

// Function to perform Breadth-First Search (BFS) on the graph
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex)
{
    bool visited[MAX_VERTICES] = {false};
    struct Queue *queue = createQueue(MAX_VERTICES);

    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                enqueue(queue, i);
            }
        }
    }

    free(queue->array);
    free(queue);
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

    // Get the starting vertex for BFS
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS
    printf("Breadth-First Search starting from vertex %d:\n", startVertex);
    bfs(graph, vertices, startVertex);

    return 0;
}
