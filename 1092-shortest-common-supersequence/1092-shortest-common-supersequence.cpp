class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int len = n + m - dp[n][m];
        string ans(len, '#');
        int i = n;
        int j = m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans[len - 1] = str1[i - 1];
                i--;
                j--;
                len--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    ans[len - 1] = str1[i - 1];
                    i--;
                    len--;
                } else {
                    ans[len - 1] = str2[j - 1];
                    j--;
                    len--;
                }
            }
        }
        while (i > 0) {
            ans[len - 1] = str1[i - 1];
            i--;
            len--;
        }
        while (j > 0) {
            ans[len - 1] = str2[j - 1];
            j--;
            len--;
        }
        return ans;
    }
};