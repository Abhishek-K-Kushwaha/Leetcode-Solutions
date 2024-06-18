class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxind = -1;
        int maxlen = 0;
        for (int i = 1; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if ((nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) &&
                        dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxlen) {
                maxlen = dp[i];
                maxind = i;
            }
        }
        vector<int> ans;
        while (true) {
            ans.push_back(nums[maxind]);
            if (hash[maxind] == maxind)
                break;
            maxind = hash[maxind];
        }
        return ans;
    }
};