class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(3, 0), nxt(3);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int state = 0; state <= 2; state++) {
                if (state == 1) { // Can buy
                    int buy = -prices[ind] + prev[0];
                    int notbuy = prev[1];
                    nxt[state] = max(buy, notbuy);
                } 
                else if (state == 0) { // Can sell
                    int sell = prices[ind] + prev[2];
                    int notsell = prev[0];
                    nxt[state] = max(sell, notsell);
                } 
                else { // Can buy next day (state = 2)
                    nxt[state] = prev[1];
                }
            }
            prev = nxt;
        }
        return nxt[1];
    }
};