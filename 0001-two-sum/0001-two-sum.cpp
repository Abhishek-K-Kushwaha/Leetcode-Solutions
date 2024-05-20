class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<int, int> dict;
        for (int i = 0; i < len; i++) {
            if (dict.find(target - nums[i]) != dict.end()) {
                return {i, dict[target - nums[i]]};
            } 
            dict[nums[i]] = i;
        }
        return {-1, -1};
    }
};