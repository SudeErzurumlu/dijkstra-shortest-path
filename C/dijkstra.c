// dijkstra.c
#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Initialize adjacency matrix with infinity
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = (i == j) ? 0 : INT_MAX; // Distance to self is 0
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjacencyMatrix[src][dest] = weight; // Add edge from src to dest
    graph->adjacencyMatrix[dest][src] = weight; // For undirected graphs, add edge back from dest to src
}

// Function to implement Dijkstra's algorithm
void dijkstra(Graph* graph, int startVertex) {
    int vertices = graph->vertices;
    int* distances = (int*)malloc(vertices * sizeof(int));
    int* visited = (int*)malloc(vertices * sizeof(int));

    // Initialize distances and visited array
    for (int i = 0; i < vertices; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }
    distances[startVertex] = 0; // Distance to the start vertex is 0

    for (int i = 0; i < vertices - 1; i++) {
        // Find the vertex with the minimum distance
        int minDistance = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < vertices; j++) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                minIndex = j;
            }
        }

        visited[minIndex] = 1; // Mark this vertex as visited

        // Update distances for the adjacent vertices
        for (int k = 0; k < vertices; k++) {
            if (!visited[k] && graph->adjacencyMatrix[minIndex][k] != INT_MAX) {
                int newDistance = distances[minIndex] + graph->adjacencyMatrix[minIndex][k];
                if (newDistance < distances[k]) {
                    distances[k] = newDistance; // Update the distance if a shorter path is found
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances from vertex %d:\n", startVertex);
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: %d\n", i, distances[i]);
    }

    free(distances);
    free(visited);
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}
