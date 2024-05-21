class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minimum = min(minimum, prices[i]);
            profit = max(profit, prices[i] - minimum);
        }
        return profit;
    }
};