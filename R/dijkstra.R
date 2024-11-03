# dijkstra.R
# Function to implement Dijkstra's algorithm to find the shortest path in a graph

create_graph <- function(vertices) {
  # Create a graph with a given number of vertices
  adjacency_matrix <- matrix(Inf, nrow = vertices, ncol = vertices)
  diag(adjacency_matrix) <- 0  # Distance to self is 0
  return(adjacency_matrix)
}

add_edge <- function(graph, src, dest, weight) {
  # Add an edge to the graph
  graph[src + 1, dest + 1] <<- weight  # R is 1-indexed
  graph[dest + 1, src + 1] <<- weight  # For undirected graphs, add edge back from dest to src
}

dijkstra <- function(graph, start_vertex) {
  vertices <- nrow(graph)
  distances <- rep(Inf, vertices)
  visited <- rep(FALSE, vertices)

  distances[start_vertex + 1] <- 0  # Distance to the start vertex is 0

  for (i in 1:(vertices - 1)) {
    # Find the vertex with the minimum distance
    min_distance <- Inf
    min_index <- -1

    for (j in 1:vertices) {
      if (!visited[j] && distances[j] < min_distance) {
        min_distance <- distances[j]
        min_index <- j
      }
    }

    visited[min_index] <- TRUE  # Mark this vertex as visited

    # Update distances for the adjacent vertices
    for (k in 1:vertices) {
      if (!visited[k] && graph[min_index, k] != Inf) {
        new_distance <- distances[min_index] + graph[min_index, k]
        if (new_distance < distances[k]) {
          distances[k] <- new_distance  # Update the distance if a shorter path is found
        }
      }
    }
  }

  return(distances)  # Return the shortest distances
}
