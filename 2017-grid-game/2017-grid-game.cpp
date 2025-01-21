class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n == 1)
            return 0;
        vector<vector<long long>> presum(2, vector<long long>(n));
        presum[1][0] = grid[1][0];
        presum[0][n - 1] = grid[0][n - 1];
        for (int i = 1; i < n; i++) {
            presum[1][i] = grid[1][i] + presum[1][i - 1];
            presum[0][n - i - 1] = grid[0][n - i - 1] + presum[0][n - i];
        }
        long long p;
        long long ans = min(presum[0][1], presum[1][n - 2]);
        for (int i = 1; i < n - 1; i++) {
            p = max(presum[0][i + 1], presum[1][i - 1]);
            ans = min(ans, p);
        }
        return ans;
    }
};