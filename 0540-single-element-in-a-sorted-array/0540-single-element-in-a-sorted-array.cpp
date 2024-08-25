class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xr = nums[0];
        for (int i = 1; i < nums.size(); i++){
            xr = xr ^ nums[i];
        }
        return xr;
    }
};