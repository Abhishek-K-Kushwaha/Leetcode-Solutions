class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        int j;
        for (int i = 0; i < n; i++){
            j = i+1;
            while (j < n && prices[j] > prices[i]) j++;
            if (j >= n) continue;
            else prices[i] -= prices[j];
        }
        return prices;
    }
};