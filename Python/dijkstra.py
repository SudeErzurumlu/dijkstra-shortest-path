# dijkstra.py
# Class for implementing Dijkstra's algorithm to find the shortest path in a graph

import heapq

class Graph:
    def __init__(self, vertices):
        self.V = vertices                              # Number of vertices in the graph
        self.adjacency_list = {i: [] for i in range(vertices)}  # Adjacency list to store edges

    def add_edge(self, u, v, weight):
        self.adjacency_list[u].append((v, weight))   # Add edge from u to v
        self.adjacency_list[v].append((u, weight))   # For undirected graphs, add edge back from v to u

    def dijkstra(self, start_vertex):
        distances = {vertex: float('infinity') for vertex in range(self.V)}  # Initialize distances to infinity
        distances[start_vertex] = 0                                             # Distance to the start vertex is 0
        priority_queue = [(0, start_vertex)]                                    # Priority queue to store vertices to visit

        while priority_queue:
            current_distance, current_vertex = heapq.heappop(priority_queue)  # Get vertex with smallest distance

            # If the distance is greater than the recorded distance, skip it
            if current_distance > distances[current_vertex]:
                continue

            for neighbor, weight in self.adjacency_list[current_vertex]:       # Explore neighbors
                distance = current_distance + weight

                # Only consider this new path if it's better
                if distance < distances[neighbor]:
                    distances[neighbor] = distance                                # Update the shortest distance
                    heapq.heappush(priority_queue, (distance, neighbor))         # Push neighbor to the queue

        return distances                                                      # Return the distances from the start vertex
