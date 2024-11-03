// dijkstra.h
// Header file for the Dijkstra algorithm to find the shortest path in a graph

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <utility>

// Graph class definition
class Graph {
public:
    Graph(int vertices);  // Constructor to initialize the graph with a number of vertices
    void addEdge(int src, int dest, int weight);  // Function to add edges to the graph
    std::vector<int> dijkstra(int startVertex);  // Function to compute the shortest path

private:
    int vertices;  // Number of vertices in the graph
    std::vector<std::vector<std::pair<int, int>>> adjList;  // Adjacency list for storing edges
};

#endif // DIJKSTRA_H
