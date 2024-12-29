class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int len = words[0].size();
        int tlen = target.size();
        if (tlen > len) return 0;
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(tlen + 1, vector<int>(len + 1, 0));
        for (int j = 0; j <= len; j++) {
            dp[tlen][j] = 1;
        }
        vector<vector<int>> freq(len, vector<int>(26, 0));
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < n; k++) {
                freq[j][words[k][j] - 'a']++;
            }
        }
        long long val;
        for (int i = tlen - 1; i >= 0; i--) {
            for (int j = len - 1; j >= 0; j--) {
                val = dp[i][j + 1];
                val += (long long)freq[j][target[i] - 'a'] * dp[i + 1][j + 1];
                val %= MOD;
                dp[i][j] = val;
            }
        }
        return dp[0][0];
    }
};