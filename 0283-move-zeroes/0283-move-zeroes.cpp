class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int iz = 0, inz = 0;
        while (inz < n && iz < n) {
            while (iz < n && nums[iz] != 0) iz++;
            while (inz < n && nums[inz] == 0) inz++;
            if (iz < n && inz < n && iz < inz) swap(nums[iz], nums[inz]);
            else inz++;
        }
    }
};