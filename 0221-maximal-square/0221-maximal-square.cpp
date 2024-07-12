class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        int ans = 0;
        // for (int i = 0; i < m; i++){
        //     for (int j = 0; j < n; j++){
        //         dp[i][j] = matrix[i][j] - '0';
        //         ans = max(ans, dp[i][j]);
        //     }
        // }
        for (int r = 0; r < m; r++){
            for (int c = 0; c < n; c++){
                if (matrix[r][c] == '1'){ 
                    if (r == 0 || c == 0) dp[r][c] = 1;
                    else dp[r][c] = 1 + min({dp[r-1][c-1], dp[r][c-1], dp[r-1][c]});
                    ans = max(ans, dp[r][c]);
                }
            }
        }
        return ans*ans;
    }
};