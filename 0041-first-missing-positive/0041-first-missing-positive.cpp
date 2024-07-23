class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            long ind = (long)nums[i] - 1;
            bool isValid = (ind >= 0 && ind < n);
            if (isValid && nums[ind] != nums[i]) {
                swap(nums[ind], nums[i]);
            } else {
                i++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};