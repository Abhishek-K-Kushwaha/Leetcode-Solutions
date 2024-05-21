class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX;
        int maximum = 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++){
            if (minimum > prices[i] && i != prices.size()-1){
                minimum = prices[i];
                maximum = prices[i];
            }
            maximum = max(maximum,prices[i]);
            profit = max(profit, maximum - minimum);
        }
        return profit;

    }
};