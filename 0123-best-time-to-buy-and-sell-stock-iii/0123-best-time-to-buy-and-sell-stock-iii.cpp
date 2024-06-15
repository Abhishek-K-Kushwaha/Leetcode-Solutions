class Solution {
public:
    int f(int ind, int cnt, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if (ind == n || cnt >= 4)
            return 0;
        if (dp[ind][cnt] != -1)
            return dp[ind][cnt];
        if (cnt % 2) { // cannot buy
            int sell = prices[ind] + f(ind + 1, cnt + 1, prices, n, dp);
            int notsell = f(ind + 1, cnt, prices, n, dp);
            return dp[ind][cnt] = max(sell, notsell);
        } else { // can buy
            int buy = -prices[ind] + f(ind + 1, cnt + 1, prices, n, dp);
            int notbuy = f(ind + 1, cnt, prices, n, dp);
            return dp[ind][cnt] = max(buy, notbuy);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(0, 0, prices, n, dp);
    }
};