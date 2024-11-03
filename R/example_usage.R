# example_usage.R
# Example usage of the Dijkstra algorithm

source("dijkstra.R")  # Load the dijkstra module

# Create a new graph instance
graph <- create_graph(5)

# Adding edges to the graph with weights
add_edge(graph, 0, 1, 10)
add_edge(graph, 0, 4, 5)
add_edge(graph, 1, 2, 1)
add_edge(graph, 1, 4, 2)
add_edge(graph, 2, 3, 4)
add_edge(graph, 3, 4, 2)
add_edge(graph, 3, 2, 6)

start_vertex <- 0  # Specify the starting vertex
distances <- dijkstra(graph, start_vertex)  # Call the dijkstra function

# Display the shortest distances from the starting vertex
cat("Shortest distances from vertex", start_vertex, ":\n")
for (vertex in 1:length(distances)) {
  cat("Vertex", vertex - 1, ":", distances[vertex], "\n")
}
