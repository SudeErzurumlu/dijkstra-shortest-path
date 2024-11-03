# example_usage.rb
# Example usage of the Dijkstra algorithm

require_relative 'dijkstra'                     # Import the dijkstra module

# Create a new graph instance
graph = Graph.new(5)

# Adding edges to the graph with weights
graph.add_edge(0, 1, 10)
graph.add_edge(0, 4, 5)
graph.add_edge(1, 2, 1)
graph.add_edge(1, 4, 2)
graph.add_edge(2, 3, 4)
graph.add_edge(3, 4, 2)
graph.add_edge(3, 2, 6)

start_vertex = 0                                  # Specify the starting vertex
distances = graph.dijkstra(start_vertex)          # Call the dijkstra method

# Display the shortest distances from the starting vertex
puts "Shortest distances from vertex #{start_vertex}:"
distances.each_with_index do |distance, index|
  puts "Vertex #{index}: #{distance}"
end
