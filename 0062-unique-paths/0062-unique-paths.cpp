class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int count = 0;
                if (i-1 >= 0) count += dp[i-1][j];
                if (j-1 >= 0) count += dp[i][j-1];
                if (i != 0 || j != 0) dp[i][j] = count;
            }
        }
        return dp[m-1][n-1];
    }
};