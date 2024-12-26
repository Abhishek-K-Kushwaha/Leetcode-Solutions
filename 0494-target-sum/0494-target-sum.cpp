class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(),0);
        if (target < -tot || target > tot) return 0;
        vector<int> prev(2*tot+1,0), curr(2*tot+1);
        prev[tot]=1;
        for (int i = n-1; i >= 0; i--){
            for (int t = 0; t < 2*tot+1; t++){
                curr[t]=0;
                if (t-tot+nums[i] <= tot) 
                    curr[t] += prev[t+nums[i]];
                if (t-tot-nums[i] >= -tot) 
                    curr[t] += prev[t-nums[i]]; 
            }
            prev = curr;
            //curr.assign(2*tot+1,0);
        }
        return prev[target+tot];
    }
};