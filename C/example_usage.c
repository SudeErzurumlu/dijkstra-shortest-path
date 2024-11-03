// example_usage.c
#include <stdio.h>
#include "dijkstra.h"

int main() {
    Graph* graph = createGraph(5); // Create a new graph with 5 vertices

    // Adding edges to the graph with weights
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 3, 2, 6);

    int startVertex = 0; // Specify the starting vertex
    dijkstra(graph, startVertex); // Call the dijkstra function

    freeGraph(graph); // Free the graph memory
    return 0;
}
