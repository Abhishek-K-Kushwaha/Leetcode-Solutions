class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> revdp(n, 1);
        for (int i = 1; i < n; i++) {
            int revi = n - 1 - i;
            for (int prev = 0; prev < i; prev++) {
                int revprev = n - 1 - prev;

                if (nums[i] > nums[prev]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }

                if (nums[revi] > nums[revprev]) {
                    revdp[revi] = max(revdp[revi], 1 + revdp[revprev]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (ans < dp[i] + revdp[i] - 1 && dp[i] != 1 && revdp[i] != 1) {
                ans = dp[i] + revdp[i] - 1;
            }
        }
        // for (int i = 0; i < n; i++){
        //     cout<< dp[i] << " ";
        // }
        // cout<< endl;
        // for (int i = 0; i < n; i++){
        //     cout<< revdp[i] << " ";
        // }
        return n - ans;
    }
};