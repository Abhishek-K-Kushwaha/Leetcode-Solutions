class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                count++;
            else {
                count = 0;
            }
            if (max_count < count)
            max_count = count;
        }
        return max_count;
    }
};