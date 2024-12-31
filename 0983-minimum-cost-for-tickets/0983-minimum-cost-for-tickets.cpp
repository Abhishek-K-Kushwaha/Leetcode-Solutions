class Solution {
public:
    int f(int i, vector<int>& days, vector<int>& costs) {
        auto it = lower_bound(days.begin(), days.end(), i);
        int ind = it - days.begin();
        if (ind >= days.size())
            return 0;
        else
            return ind;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int maxday = days[n - 1];
        vector<int> dp(n + 1);
        int d1, d7, d30;
        for (int i = n - 1; i >= 0; i--) {
            d1 = costs[0] + dp[f(days[i] + 1, days, costs)];
            d7 = costs[1] + dp[f(days[i] + 7, days, costs)];
            d30 = costs[2] + dp[f(days[i] + 30, days, costs)];
            dp[i] = min(d1, min(d7, d30));
        }
        return dp[0];
    }
};