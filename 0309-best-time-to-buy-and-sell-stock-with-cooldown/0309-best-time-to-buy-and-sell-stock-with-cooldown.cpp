class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(3, 0), nxt(3);
        for (int ind = n - 1; ind >= 0; ind--) {
            //if (state == 1) Can buy
            int buy = -prices[ind] + prev[0];
            int notbuy = prev[1];
            nxt[1] = max(buy, notbuy);

            //else if (state == 0) Can sell
            int sell = prices[ind] + prev[2];
            int notsell = prev[0];
            nxt[0] = max(sell, notsell);
            
            //else Can buy next day (state == 2)
            nxt[2] = prev[1];
            prev = nxt;
        }
        return nxt[1];
    }
};