class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));
        for (int i = c - 2; i >= 1; i--){
            for (int j = i; j <= c -2; j++){
                int ans = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1];
                    cost += dp[i][k-1];
                    cost += dp[k+1][j];
                    ans = min(ans, cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][c-2];
    }
};