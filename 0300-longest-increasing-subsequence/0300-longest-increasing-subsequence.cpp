class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> row(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = -1; prev < ind; prev++) {
                if (prev == -1 || nums[ind] > nums[prev]) {
                    int pick = 1 + row[ind + 1];
                    int notpick = row[prev + 1];
                    row[prev + 1] = max(pick, notpick);
                } 
            }
        }
        return row[0];
    }
};