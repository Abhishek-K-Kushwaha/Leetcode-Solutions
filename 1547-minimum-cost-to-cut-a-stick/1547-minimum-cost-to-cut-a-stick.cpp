class Solution {
public:
    int f(int i, int j, vector<int>& cuts, unordered_map<long long,int>& dp, int n) {
        if (j - i <= 1) return 0;
        long long key = (long long)i*n + j;
        if (dp.find(key) != dp.end()) return dp[key];
        int ans = 1e9;
        int flag = 0;
        for (int k : cuts) {
            if (k > i && k < j) {
                flag = 1;
                int cost = (j - i) + f(i, k, cuts, dp, n) + f(k, j, cuts, dp, n);
                ans = min(ans, cost);
            }
        }
        if (!flag) return dp[key] = 0;
        else return dp[key] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        //vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        unordered_map<long long,int> dp;
        return f(0, n, cuts, dp, n);
    }
};