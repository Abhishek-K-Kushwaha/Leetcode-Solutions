class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = 0;
        for (int num : nums) {
            sum += num;
            n++;
        }
        if ((sum - target) % 2 != 0)
            return 0;
        int d = (sum - target) / 2;
        if (d < 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t <= d; t++) {
                int notpick = dp[i - 1][t];
                int pick = 0;
                if (nums[i - 1] <= t)
                    pick = dp[i - 1][t - nums[i - 1]];
                dp[i][t] = pick + notpick;
            }
        }
        return dp[n][d];
    }
};