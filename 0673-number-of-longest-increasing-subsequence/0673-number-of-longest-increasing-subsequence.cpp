class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);
        hash[0] = 1;
        int maxlen = 1;
        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    if (dp[i] < 1 + dp[prev]) {
                        dp[i] = max(dp[i], 1 + dp[prev]);
                        hash[i] = hash[prev];
                    } else if (dp[i] == 1 + dp[prev]) {
                        hash[i] += hash[prev];
                    }
                }
            }
            if (maxlen < dp[i]) {
                maxlen = dp[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (maxlen == dp[i]) {
                ans += hash[i];
            }
        }
        return ans;
    }
};