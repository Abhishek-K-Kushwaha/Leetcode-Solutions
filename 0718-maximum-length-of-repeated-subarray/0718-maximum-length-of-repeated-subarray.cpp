class Solution {
public:
    int findLength(vector<int>& S1, vector<int>& S2) {
        int n = S1.size();
        int m = S2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxl = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S1[i - 1] == S2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxl = max(maxl, dp[i][j]);
                }
            }
        }
        return maxl;
    }
};