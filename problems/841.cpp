class Solution {
public:
    void dfs (vector<vector<int>>& graph, int node, vector<bool>& visited, int* count) {
        visited[node] = true;
        (*count)++;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs (graph, neighbor, visited, count);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);

        int count = 0;

        dfs (rooms, 0, visited, &count);

        if (count == rooms.size())
            return true;
        
        return false;
    }
};