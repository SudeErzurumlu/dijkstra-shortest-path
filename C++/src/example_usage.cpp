// example_usage.cpp
// Demonstrates the use of Dijkstra's algorithm for finding the shortest path

#include <iostream>
#include "dijkstra.h"

int main() {
    int vertices = 5;  // Number of vertices in the graph
    Graph g(vertices);

    // Adding edges to the graph with weights
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 2, 6);

    int startVertex = 0;  // Starting vertex for the shortest path search
    std::vector<int> distances = g.dijkstra(startVertex);

    // Display the shortest distances from the starting vertex
    for (int i = 0; i < distances.size(); i++) {
        std::cout << "Distance from vertex " << startVertex << " to vertex " << i << ": " << distances[i] << std::endl;
    }

    return 0;
}
