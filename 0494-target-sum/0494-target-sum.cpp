class Solution {
public:
    int f(int ind, int tar, vector<int>& nums, vector<vector<int>>& dp, int offset){
        if (dp[ind][tar + offset] != -1) return dp[ind][tar + offset];
        if (ind == 0){
            int cnt = 0;
            if (nums[ind] == tar) cnt++;
            if (nums[ind] == -tar) cnt++;
            return dp[ind][tar + offset] = cnt;
        }
        int pos = f(ind-1, tar - nums[ind], nums, dp, offset);
        int neg = f(ind-1, tar + nums[ind], nums, dp, offset);
        return dp[ind][tar + offset] = pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = 10000;
        vector<vector<int>> dp(n, vector<int>(20001, -1));
        return f(n-1, target, nums, dp, offset);
    }
};
