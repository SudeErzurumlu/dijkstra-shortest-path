// dijkstra.h
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <limits.h>

// Structure to represent a graph
typedef struct {
    int vertices;                     // Number of vertices in the graph
    int** adjacencyMatrix;           // Adjacency matrix to store edges
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices);

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight);

// Function to implement Dijkstra's algorithm
void dijkstra(Graph* graph, int startVertex);

// Function to free the graph memory
void freeGraph(Graph* graph);

#endif
