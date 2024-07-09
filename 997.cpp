class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n+1);
        vector<int> count(n+1);

        for (int i = 0; i < trust.size(); i++) {
            graph[trust[i][0]].push_back(trust[i][1]);
            count[trust[i][1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (count[i] == n - 1 && graph[i].size() == 0) {
                return i;
            }
        }

        return (-1);
    }
};