// dijkstra.cpp
// Implementation file for Dijkstra’s shortest path algorithm

#include "dijkstra.h"
#include <vector>
#include <queue>
#include <limits>

// Constructor initializes the graph with a given number of vertices
Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}

// Adds an edge between source and destination with a specified weight
void Graph::addEdge(int src, int dest, int weight) {
    adjList[src].push_back({dest, weight});
    adjList[dest].push_back({src, weight});  // For undirected graphs
}

// Implementation of Dijkstra's algorithm to find the shortest path from startVertex
std::vector<int> Graph::dijkstra(int startVertex) {
    std::vector<int> distances(vertices, std::numeric_limits<int>::max());  // Initialize distances to infinity
    distances[startVertex] = 0;  // Distance to itself is 0

    // Min-heap priority queue to fetch the minimum distance node
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (distance > distances[vertex]) continue;  // Skip if the current distance is already optimal

        // Traverse all adjacent vertices
        for (const auto& neighbor : adjList[vertex]) {
            int nextVertex = neighbor.first;
            int edgeWeight = neighbor.second;

            int newDist = distances[vertex] + edgeWeight;
            // Update distance if a shorter path is found
            if (newDist < distances[nextVertex]) {
                distances[nextVertex] = newDist;
                pq.push({newDist, nextVertex});
            }
        }
    }
    return distances;  // Return the computed shortest distances
}
