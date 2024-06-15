class Solution {
public:
    int f(int ind, int state, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if (ind == n)
            return 0;
        if (dp[ind][state] != -1)
            return dp[ind][state];
        if (state == 1) { // Can buy
            int buy = -prices[ind] + f(ind + 1, 0, prices, n, dp);
            int notbuy = f(ind + 1, 1, prices, n, dp);
            return dp[ind][state] = max(buy, notbuy);
        } else if (state == 0) { // Can sell
            int sell = prices[ind] + f(ind + 1, 2, prices, n, dp);
            int notsell = f(ind + 1, 0, prices, n, dp);
            return dp[ind][state] = max(sell, notsell);
        } else { // Can buy next day (state = 2)
            return dp[ind][state] = f(ind + 1, 1, prices, n, dp);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return f(0, 1, prices, n, dp);
    }
};