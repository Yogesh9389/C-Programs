#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Queue {
    int front, rear;
    int items[MAX_VERTICES];
};

struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue an item into the queue
void enqueue(struct Queue* queue, int item) {
    if (queue->rear == MAX_VERTICES - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = item;
}

// Function to dequeue an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return item;
}

// Function to create a new graph
struct Graph* createGraph(int numVertices) {
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->numVertices = numVertices;

    // Initialize the adjacency matrix with 0 for all edges
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            newGraph->adjacencyMatrix[i][j] = 0;
        }
    }

    return newGraph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    if (startVertex >= graph->numVertices || endVertex >= graph->numVertices) {
        printf("Invalid vertex IDs. Vertex IDs should be less than the number of vertices.\n");
        return;
    }

    graph->adjacencyMatrix[startVertex][endVertex] = 1;
    graph->adjacencyMatrix[endVertex][startVertex] = 1;
}

// Function to perform Breadth-First Search (BFS) on the graph
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};

    struct Queue* queue = createQueue();
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    printf("BFS Traversal: ");
    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
}

// Function to display the menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add an edge\n");
    printf("2. Perform BFS\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70\n");
    struct Graph* graph = NULL;
    int numVertices, choice, startVertex, endVertex;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (graph == NULL) {
                    printf("Enter the number of vertices: ");
                    scanf("%d", &numVertices);
                    graph = createGraph(numVertices);
                }
                printf("Enter the start vertex ID: ");
                scanf("%d", &startVertex);
                printf("Enter the end vertex ID: ");
                scanf("%d", &endVertex);
                addEdge(graph, startVertex, endVertex);
                printf("Edge added.\n");
                break;
            case 2:
                if (graph == NULL) {
                    printf("Graph not created. Please create the graph first.\n");
                } else {
                    printf("Enter the starting vertex for BFS: ");
                    scanf("%d", &startVertex);
                    BFS(graph, startVertex);
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
