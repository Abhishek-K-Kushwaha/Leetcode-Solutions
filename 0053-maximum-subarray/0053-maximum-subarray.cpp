class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minsum = nums[0];
        int maxsum = nums[0];
        int presum = nums[0];
        for (int i = 1; i < nums.size(); i++){
            presum += nums[i];
            if (presum > maxsum) maxsum = presum;
            if ((presum - minsum) > maxsum) maxsum = (presum - minsum);
            if (presum < minsum) minsum = presum;
        }
        return maxsum;
    }
};