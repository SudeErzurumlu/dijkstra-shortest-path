% example_usage.m
% Example usage of the Dijkstra algorithm

% Define the adjacency matrix for the graph
adjMatrix = [0 10 0 0 5;
             0 0 1 0 2;
             0 0 0 4 0;
             0 0 0 0 2;
             0 3 9 0 0];

% Specify the starting node
startNode = 1;

% Call the dijkstra function
distances = dijkstra(adjMatrix, startNode);

% Display the shortest distances from startNode to each node
fprintf('Shortest distances from node %d:\n', startNode);
for i = 1:length(distances)
    fprintf('Node %d: %f\n', i, distances(i));
end
