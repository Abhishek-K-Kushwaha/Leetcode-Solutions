class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rcnt(m, 0), ccnt(n, 0);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]){
                    rcnt[i]++;
                    ccnt[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans += (grid[i][j] && (rcnt[i] > 1 || ccnt[j] > 1));
            }
        }
        return ans;
    }
};