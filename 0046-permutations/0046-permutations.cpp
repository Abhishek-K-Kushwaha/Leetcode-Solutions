class Solution {
public:
    vector<vector<int>> res;
    int n;
    void f(vector<int>& nums, int curr){
        if (curr == n-1) {
            res.push_back(nums);
            return;
        }
        for (int i = curr; i < nums.size(); i++){
            swap(nums[i], nums[curr]);
            f(nums, curr + 1);
            swap(nums[i], nums[curr]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        f(nums, 0);
        return res;
    }
};