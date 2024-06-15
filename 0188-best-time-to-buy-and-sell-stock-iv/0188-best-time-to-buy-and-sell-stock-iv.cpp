class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2*k+1,0);
        for (int ind = n-1; ind >= 0; ind--){
            for (int cnt = 2*k-1; cnt >= 0; cnt--){
                if (cnt % 2) { // cannot buy
                    int sell = prices[ind] + prev[cnt+1]; 
                    int notsell = prev[cnt]; 
                    prev[cnt] = max(sell, notsell);
                } else { // can buy
                    int buy = -prices[ind] + prev[cnt+1]; 
                    int notbuy = prev[cnt]; 
                    prev[cnt] = max(buy, notbuy);
                }
            }
        }
        return prev[0];
    }
};