class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len = nums.size();
        int posind = 0;
        int negind = 1;
        vector<int> ans(len);
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) {
                ans[posind] = nums[i];
                posind += 2;
            } else {
                ans[negind] = nums[i];
                negind += 2;
            }
        }
        return ans;
    }
};
