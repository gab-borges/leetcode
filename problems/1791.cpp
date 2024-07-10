class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<int> count(n+1);

        for(int i = 0; i < edges.size(); i++) {
            count[edges[i][0]]++;
            count[edges[i][1]]++;
        }

        for(int i = 1; i <= n; i++)
            if(count[i] == n - 1)
                return (i);

        return 0;
    }
};