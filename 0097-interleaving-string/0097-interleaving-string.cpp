class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int l = s3.size();
        if (m+n != l) return false;
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for (int i = m; i >= 0; i--){
            for (int j = n; j >= 0; j--){
                int k = i + j;
                if (k == l) {
                    dp[i][j] = true;
                    continue;
                }
                bool first = false;
                bool second = false;
                if (i < m && s1[i] == s3[k]){
                    first = dp[i+1][j]; //f(i+1, j, s1, s2, s3, dp);
                }
                if (j < n && s2[j] == s3[k]){
                    second = dp[i][j+1]; //f(i, j+1, s1, s2, s3, dp);
                }
                dp[i][j] = (first || second);
            }
        }
        return dp[0][0]; //f(0,0,s1,s2,s3, dp);
    }
};