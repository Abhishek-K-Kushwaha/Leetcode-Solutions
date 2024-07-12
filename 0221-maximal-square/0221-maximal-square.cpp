class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                dp[i][j] = matrix[i][j] - '0';
                cout<< dp[i][j] << " ";
                ans = max(ans, dp[i][j]);
            }
            cout<< "\n";
        }
        for (int r = 1; r < m; r++){
            for (int c = 1; c < n; c++){
                if (dp[r][c]) dp[r][c] = dp[r][c] + min({dp[r-1][c-1], dp[r][c-1], dp[r-1][c]});
                cout<< dp[r][c] << " ";
                ans = max(ans, dp[r][c]);
            }
            cout<< "\n";
        }
        return ans*ans;
    }
};