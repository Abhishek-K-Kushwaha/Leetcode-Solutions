class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        //long long tot = accumulate(nums.begin(), nums.end(),0);
        long long tot = 0;
        for (int i:nums){
            tot += i;
        }
        long long sum = 0, ans = 0;
        for (int i = 0; i < n-1; i++){
            sum += nums[i];
            if (sum >= tot - sum) ans++;
        }
        return ans;
    }
};