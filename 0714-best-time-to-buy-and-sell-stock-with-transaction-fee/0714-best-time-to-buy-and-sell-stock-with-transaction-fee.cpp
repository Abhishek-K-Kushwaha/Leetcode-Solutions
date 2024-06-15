class Solution {
public:
    int f(int ind, int canbuy, vector<int>& prices, int n, int fee, vector<vector<int>>& dp) {
        if (ind == n)
            return 0;
        if (dp[ind][canbuy] != -1) return dp[ind][canbuy];
        if (canbuy) {
            int buy = -prices[ind] + f(ind + 1, 0, prices, n, fee, dp);
            int notbuy = f(ind + 1, 1, prices, n, fee, dp);
            return dp[ind][canbuy] = max(buy, notbuy);
        } else {
            int sell = prices[ind] - fee + f(ind + 1, 1, prices, n, fee, dp);
            int notsell = f(ind + 1, 0, prices, n, fee, dp);
            return dp[ind][canbuy] = max(sell, notsell);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n, fee, dp);
    }
};