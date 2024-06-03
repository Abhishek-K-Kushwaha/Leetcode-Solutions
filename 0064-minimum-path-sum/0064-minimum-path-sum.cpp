class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp = grid;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0 || j != 0) {
                    int up = INT_MAX, left = INT_MAX;
                    if (i - 1 >= 0)
                        up = dp[i - 1][j];
                    if (j - 1 >= 0)
                        left = dp[i][j - 1];
                    dp[i][j] += min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};