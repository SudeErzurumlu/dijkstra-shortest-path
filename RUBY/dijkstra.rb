# dijkstra.rb
# Class for implementing Dijkstra's algorithm to find the shortest path in a graph

class Graph
  def initialize(vertices)
    @vertices = vertices                       # Number of vertices in the graph
    @adjacency_list = Array.new(vertices) { [] }  # Adjacency list to store edges
  end

  def add_edge(src, dest, weight)
    @adjacency_list[src] << [dest, weight]    # Add edge from src to dest
    @adjacency_list[dest] << [src, weight]    # For undirected graphs, add edge back from dest to src
  end

  def dijkstra(start_vertex)
    distances = Array.new(@vertices, Float::INFINITY)  # Initialize distances to infinity
    distances[start_vertex] = 0                    # Distance to the start vertex is 0
    visited = Array.new(@vertices, false)          # Track visited vertices

    (@vertices).times do
      u = minimum_distance_vertex(distances, visited)  # Find the unvisited vertex with the smallest distance
      visited[u] = true                               # Mark this vertex as visited

      @adjacency_list[u].each do |neighbor|
        next_vertex, weight = neighbor                # Extract the neighboring vertex and weight
        if !visited[next_vertex]
          new_distance = distances[u] + weight
          if new_distance < distances[next_vertex]
            distances[next_vertex] = new_distance    # Update the distance if a shorter path is found
          end
        end
      end
    end

    distances                                       # Return the distances from the start vertex
  end

  private

  def minimum_distance_vertex(distances, visited)
    min_distance = Float::INFINITY
    min_index = -1

    distances.each_with_index do |distance, index|
      if !visited[index] && distance < min_distance
        min_distance = distance
        min_index = index
      end
    end

    min_index                                       # Return the index of the minimum distance vertex
  end
end
