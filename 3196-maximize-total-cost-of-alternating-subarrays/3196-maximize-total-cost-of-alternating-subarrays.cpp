class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long> (3));
        dp[0][0] = nums[0], dp[0][1] = nums[0], dp[0][2] = nums[0];
        for (int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][2], dp[i-1][2])) + nums[i];
            //dp[i][1] = dp[i-1][2]+nums[i];
            dp[i][2]= max(dp[i-1][0], dp[i-1][0])-nums[i];
            //cout << dp[i][0] << " " <<dp[i][1] << " "<< dp[i][2]<< endl;
        } 
        return max(dp[n-1][0], max(dp[n-1][2], dp[n-1][2]));
    }
};