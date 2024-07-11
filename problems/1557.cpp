class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 0) {
                ans.push_back(i);
            }
        }

        return (ans);
    }
};