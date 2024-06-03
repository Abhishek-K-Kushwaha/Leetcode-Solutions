class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]) dp[i][j] = 0;
                else{
                    if (i != 0 || j != 0 ){
                        if (i-1 >= 0) dp[i][j] += dp[i-1][j];
                        if (j-1 >= 0) dp[i][j] += dp[i][j-1];
                    }
                }
                //cout<< "Value: "<<dp[i][j] << " i="<< i<< " j="<<j<<" ";
            }
        }
        return dp[m-1][n-1];
    }
};