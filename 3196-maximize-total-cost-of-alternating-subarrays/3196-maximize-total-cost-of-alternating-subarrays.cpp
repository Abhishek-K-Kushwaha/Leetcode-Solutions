class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<long long>> dp(n, vector<long long> (2));
        //dp[0][0] = nums[0], dp[0][1] = nums[0];
        long long p0 = nums[0], p1 = nums[0], c0, c1;
        for (int i = 1; i < n; i++){
            //dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + nums[i];
            c0 = max(p0, p1) + nums[i];
            //dp[i][1]= dp[i-1][0]-nums[i];
            c1 = p0 - nums[i];
            p0 = c0, p1 = c1; 
        } 
        return max(p0, p1);
    }
};