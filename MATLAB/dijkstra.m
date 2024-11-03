% dijkstra.m
% Finds the shortest path from a starting node to all other nodes in a graph

function distances = dijkstra(adjMatrix, startNode)
    % Inputs:
    % - adjMatrix: NxN adjacency matrix, where adjMatrix(i,j) represents the
    %              weight of the edge from node i to node j (0 if no edge exists)
    % - startNode: The starting node for finding the shortest path
    
    % Output:
    % - distances: A vector of minimum distances from startNode to all other nodes

    numNodes = size(adjMatrix, 1);               % Number of nodes in the graph
    distances = inf(1, numNodes);                % Initialize distances as infinity
    distances(startNode) = 0;                    % Distance to startNode is zero
    visited = false(1, numNodes);                % Track visited nodes
    
    for i = 1:numNodes
        % Find the unvisited node with the smallest distance
        [~, u] = min(distances + visited * max(distances));
        visited(u) = true;                       % Mark this node as visited
        
        % Update distances for each neighbor of node u
        for v = 1:numNodes
            if adjMatrix(u, v) > 0 && ~visited(v)  % Check if there's an edge and node v is unvisited
                newDist = distances(u) + adjMatrix(u, v);
                if newDist < distances(v)
                    distances(v) = newDist;       % Update distance if a shorter path is found
                end
            end
        end
    end
end
