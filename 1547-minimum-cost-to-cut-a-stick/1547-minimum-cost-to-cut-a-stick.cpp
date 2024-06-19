class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for (int k = i; k <= j; k++){
            int cost = cuts[j+1] - cuts[i-1];
            cost += f(i, k-1, cuts, dp);
            cost+= f(k+1, j, cuts, dp);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(), 0);
        int j = cuts.size() - 1;
        cuts.push_back(n);
        vector<vector<int>> dp(j+1, vector<int> (j+1,-1));
        return f(1, j, cuts, dp);
    }
};