class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev = max(nums[0],nums[1]);
        int prev2 = nums[0];
        for (int i = 2; i < n; i++){
            int pick = nums[i] + prev2;
            int notpick = 0 + prev;
            int temp = max(pick, notpick);
            prev2 = prev;
            prev = temp;
        }
        return prev;
    }
};