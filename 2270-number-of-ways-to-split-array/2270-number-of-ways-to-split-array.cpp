class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(),0);
        int sum = 0, ans = 0;
        for (int i = 0; i < n-1; i++){
            sum += nums[i];
            if (sum >= tot - sum) ans++;
        }
        return ans;
    }
};