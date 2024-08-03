class Solution {
public:
    int f(int i, int own, vector<int>& prices, int fee, vector<vector<int>>& dp){
        if (i == prices.size()) return 0;
        if (dp[i][own] != -1) return dp[i][own];
        int profit = 0;
        if (own){
            int sell = prices[i] - fee + f(i+1, 0, prices, fee, dp);
            int notsell = f(i+1, 1, prices, fee, dp);
            profit = max({sell, notsell, profit});
        }
        else{
            int buy = -prices[i] + f(i+1, 1, prices, fee, dp);
            int notbuy = f(i+1, 0, prices, fee, dp);
            profit = max({buy , notbuy, profit});
        }
        return dp[i][own] = profit;

    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for (int i = n-1; i >=0; i--){
            for (int own = 0; own <= 1; own++){
                int profit = 0;
                if (own){
                    int sell = prices[i] - fee + dp[i+1][0]; //f(i+1, 0, prices, fee, dp);
                    int notsell = dp[i+1][1]; //f(i+1, 1, prices, fee, dp);
                    profit = max({sell, notsell, profit});
                }
                else{
                    int buy = -prices[i] + dp[i+1][1]; //f(i+1, 1, prices, fee, dp);
                    int notbuy = dp[i+1][0]; //f(i+1, 0, prices, fee, dp);
                    profit = max({buy , notbuy, profit});
                }
                dp[i][own] = profit;
            }
        }
        return dp[0][0]; //f(0, 0, prices, fee, dp);
    }
};