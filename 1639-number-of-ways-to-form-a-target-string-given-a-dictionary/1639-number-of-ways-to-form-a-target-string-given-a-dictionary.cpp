class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int len = words[0].size();
        int tlen = target.size();
        if (tlen > len) return 0;
        int MOD = 1e9 + 7;
        // vector<vector<int>> dp(tlen + 1, vector<int>(len + 1, 0));
        // for (int j = 0; j <= len; j++) {
        //     dp[tlen][j] = 1;
        // }
        vector<vector<int>> freq(len, vector<int>(26, 0));
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < n; k++) {
                freq[j][words[k][j] - 'a']++;
            }
        }
        vector<int> prev(len + 1, 1);
        vector<int> curr(len + 1);
        curr[len] = 0;
        long long val;
        for (int i = tlen - 1; i >= 0; i--) {
            //curr[len] = 0;
            for (int j = len - 1; j >= 0; j--) {
                val = curr[j + 1];
                val += (long long)freq[j][target[i] - 'a'] * prev[j + 1];
                val %= MOD;
                curr[j] = val;
            }
            prev = curr;
        }
        return prev[0];
    }
};