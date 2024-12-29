class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> presum;
        int ans = 0;
        int sum = 0;
        for (int i:nums){
            sum += i;
            if (sum == k) ans++;
            ans += presum[sum-k];
            presum[sum]++; 
        }
        return ans;
    }
};