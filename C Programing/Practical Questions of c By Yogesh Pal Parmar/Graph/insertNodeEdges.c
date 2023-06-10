#include <stdio.h>
#include <stdlib.h>

// Graph structure
struct Graph {
    int numNodes;
    int** adjLists;
};

// Create a graph
struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;

    // Allocate memory for the array of pointers
    graph->adjLists = (int**)malloc(numNodes * sizeof(int*));

    // Initialize each pointer to NULL
    int i;
    for (i = 0; i < numNodes; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from source to destination

    // Allocate memory for the destination node
    int* newNode = (int*)malloc(sizeof(int));
    *newNode = dest;

    // Update the source node's adjacency list
    int** adjList = &(graph->adjLists[src]);
    *adjList = newNode;

    // Since the graph is undirected, add an edge from destination to source as well
    newNode = (int*)malloc(sizeof(int));
    *newNode = src;

    // Update the destination node's adjacency list
    adjList = &(graph->adjLists[dest]);
    *adjList = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < graph->numNodes; i++) {
        int* adjNode = graph->adjLists[i];
        printf("Adjacency list of node %d: ", i);
        if (adjNode) {
            printf("%d -> ", *adjNode);
        }
        printf("NULL\n");
    }
}

// Test the graph implementation
int main() {
    int numNodes = 5;
    struct Graph* graph = createGraph(numNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
