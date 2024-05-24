class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int majority1 = 0;
        int majority2 = 0;

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] == majority1) {
                count1++;
            } else if (nums[i] == majority2) {
                count2++;
            } else if (count1 == 0) {
                majority1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                majority2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (auto num : nums) {
            if (num == majority1) {
                count1++;
            } else if (num == majority2) {
                count2++;
            }
        }
        if (count1 > n / 3)
            result.push_back(majority1);
        if (count2 > n / 3)
            result.push_back(majority2);
        return result;
    }
};