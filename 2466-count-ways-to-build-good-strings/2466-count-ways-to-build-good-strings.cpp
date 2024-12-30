class Solution {
public:
    int countGoodStrings(int low, int high, int n0, int n1) {
        vector<int> dp(high + 1);
        long long ans;
        int mod = 1e9 + 7;
        for (int i = high; i >= 0; i--) {
            ans = (i >= low);
            if (i+n0 <= high) ans += dp[i + n0];
            if (i+n1 <= high) ans += dp[i + n1];
            ans %= mod;
            dp[i] = ans;
        }
        return dp[0];
    }
};