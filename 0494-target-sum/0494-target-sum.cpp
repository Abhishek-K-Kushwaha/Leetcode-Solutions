class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (2001, 0));
        dp[n][1000]=1;
        //int ways;
        for (int i = n-1; i >= 0; i--){
            for (int t = 0; t < 2001; t++){
                if (t-1000+nums[i] <= 1000 && t-1000+nums[i] >= -1000) 
                    dp[i][t] += dp[i+1][t+nums[i]];
                if (t-1000-nums[i] <= 1000 && t-1000-nums[i] >= -1000) 
                    dp[i][t] += dp[i+1][t-nums[i]]; 
                //if (dp[i][t])cout << dp[i][t] << " "<< i<<" "<< t-1000<< endl;
            }
        }
        return dp[0][target+1000];
    }
};