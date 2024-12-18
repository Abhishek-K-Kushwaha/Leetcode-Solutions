class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> stk;
        int j;
        for (int i = 0; i < n; i++) {
            while (!stk. empty() && prices[i] <= prices[stk.top()]){
                j = stk.top();
                prices[j] -= prices[i];
                //cout << prices[j] << endl;
                stk.pop();
            }
            stk.push(i);
        }
        return prices;
    }
};