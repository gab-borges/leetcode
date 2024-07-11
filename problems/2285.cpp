class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long> connections(n, 0);

        for (int i = 0; i < roads.size(); i++) {
            connections[roads[i][0]]++;
            connections[roads[i][1]]++;
        }
        
        sort(connections.begin(), connections.end());

        long sum = 0;

        for (int i = 0; i < n; i++)
            sum += connections[i] * (i+1);
            
        return (sum);
    }
};
