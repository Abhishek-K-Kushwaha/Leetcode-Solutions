class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int state = 0; state <= 2; state++) {
                if (state == 1) { // Can buy
                    int buy = -prices[ind] + dp[ind + 1][0];
                    int notbuy = dp[ind + 1][1];
                    dp[ind][state] = max(buy, notbuy);
                } else if (state == 0) { // Can sell
                    int sell = prices[ind] + dp[ind + 1][2];
                    int notsell = dp[ind + 1][0];
                    dp[ind][state] = max(sell, notsell);
                } else { // Can buy next day (state = 2)
                    dp[ind][state] = dp[ind + 1][1];
                }
            }
        }
        return dp[0][1];
    }
};