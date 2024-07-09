class Solution {
public:
    bool bfs (vector<list<int>>& graph, int source, int destination, vector<bool>& visited) {
        queue<int> searchQueue;

        searchQueue.push(source);
        visited[source] = true;

        while(!searchQueue.empty()) {
            int currentNode = searchQueue.front();
            searchQueue.pop();

            if (currentNode == destination)
                return true;

            for (int neighbor : graph[currentNode]) {
                if (!visited[neighbor]) {
                    searchQueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<list<int>> graph(n);
        
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);

        return (bfs (graph, source, destination, visited));
    }
};