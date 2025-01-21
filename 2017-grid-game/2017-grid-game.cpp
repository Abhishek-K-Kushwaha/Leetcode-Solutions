class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            tot += grid[0][i];
        }
        long long p = 0;
        long long ans = 1e18;
        for (int i = 0; i < n; i++) {
            tot -= grid[0][i];
            ans = min(ans, max(tot, p));
            p += grid[1][i];
        }
        return ans;
    }
};