class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> prev(2,0), nxt(2);
        for (int ind = n-1; ind >= 0; ind--){
            //if (canbuy == 1) {
            int buy = -prices[ind] + prev[0]; 
            int notbuy = prev[1]; 
            nxt[1] = max(buy, notbuy);

            // else if (canbuy == 0)
            int sell = prices[ind] - fee + prev[1]; 
            int notsell = prev[0]; 
            nxt[0] = max(sell, notsell);
            prev = nxt;
        }
        return prev[1];
    }
};