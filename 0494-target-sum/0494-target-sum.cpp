class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prev(2001,0), curr(2001);
        prev[1000]=1;
        for (int i = n-1; i >= 0; i--){
            for (int t = 0; t < 2001; t++){
                curr[t]=0;
                if (t-1000+nums[i] <= 1000) 
                    curr[t] += prev[t+nums[i]];
                if (t-1000-nums[i] >= -1000) 
                    curr[t] += prev[t-nums[i]]; 
                //if (dp[i][t])cout << dp[i][t] << " "<< i<<" "<< t-1000<< endl;
            }
            prev = curr;
        }
        return curr[target+1000];
    }
};