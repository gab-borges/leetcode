class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, int dest, vector<bool>& visited, vector<vector<int>>& paths, vector<int>& currentPath) {
        if (node == dest) {
            paths.push_back(currentPath);
            return;
        }

        visited[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                currentPath.push_back(neighbor);
                dfs (graph, neighbor, dest, visited, paths, currentPath);
                currentPath.pop_back();
            }
        }

        visited[node] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> visited(n, false);
        
        vector<vector<int>> paths;

        vector<int> currentPath(1);

        dfs (graph, 0, n-1, visited, paths, currentPath);

        return (paths);
    }
};