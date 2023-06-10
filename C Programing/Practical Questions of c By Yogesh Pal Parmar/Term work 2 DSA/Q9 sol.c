#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Vertex {
    int vertexID;
    int weight;
};

struct Graph {
    int numVertices;
    struct Vertex* vertices[MAX_VERTICES];
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a new vertex
struct Vertex* createVertex(int vertexID, int weight) {
    struct Vertex* newVertex = (struct Vertex*)malloc(sizeof(struct Vertex));
    newVertex->vertexID = vertexID;
    newVertex->weight = weight;
    return newVertex;
}

// Function to create a new graph
struct Graph* createGraph(int numVertices) {
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->numVertices = numVertices;

    // Initialize the adjacency matrix with 0 weight for all edges
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            newGraph->adjacencyMatrix[i][j] = 0;
        }
    }

    // Initialize the vertices array with NULL
    for (int i = 0; i < numVertices; i++) {
        newGraph->vertices[i] = NULL;
    }

    return newGraph;
}

// Function to add a vertex to the graph
void addVertex(struct Graph* graph, int vertexID, int weight) {
    if (vertexID >= graph->numVertices) {
        printf("Invalid vertex ID. Vertex ID should be less than the number of vertices.\n");
        return;
    }

    struct Vertex* newVertex = createVertex(vertexID, weight);
    graph->vertices[vertexID] = newVertex;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int startVertexID, int endVertexID, int weight) {
    if (startVertexID >= graph->numVertices || endVertexID >= graph->numVertices) {
        printf("Invalid vertex IDs. Vertex IDs should be less than the number of vertices.\n");
        return;
    }

    graph->adjacencyMatrix[startVertexID][endVertexID] = weight;
    graph->adjacencyMatrix[endVertexID][startVertexID] = weight;
}

// Function to display the graph details
void displayGraph(struct Graph* graph) {
    printf("Graph Details:\n");
    printf("Number of Vertices: %d\n", graph->numVertices);
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Vertex Details:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i] != NULL) {
            printf("Vertex ID: %d, Weight: %d\n", graph->vertices[i]->vertexID, graph->vertices[i]->weight);
        }
    }
}

// Function to display the menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add a vertex\n");
    printf("2. Add an edge\n");
    printf("3. Display graph details\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70\n");
    struct Graph* graph = NULL;
    int numVertices, choice, startVertex, endVertex, weight;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (graph != NULL) {
                    printf("Graph already created. Please choose another option.\n");
                } else {
                    printf("Enter the number of vertices: ");
                    scanf("%d", &numVertices);
                    graph = createGraph(numVertices);
                    printf("Graph created.\n");
                }
                break;
            case 2:
                if (graph == NULL) {
                    printf("Graph not created. Please create the graph first.\n");
                } else {
                    printf("Enter the start vertex ID: ");
                    scanf("%d", &startVertex);
                    printf("Enter the end vertex ID: ");
                    scanf("%d", &endVertex);
                    printf("Enter the weight: ");
                    scanf("%d", &weight);
                    addEdge(graph, startVertex, endVertex, weight);
                    printf("Edge added.\n");
                }
                break;
            case 3:
                if (graph == NULL) {
                    printf("Graph not created. Please create the graph first.\n");
                } else {
                    displayGraph(graph);
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
