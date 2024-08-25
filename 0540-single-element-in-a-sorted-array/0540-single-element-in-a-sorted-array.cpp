class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = (n-1)/2;
        int ans = -1;
        while (i <= j){
            int mid = (i+j)/2;
            int ind = 2*mid;
            if (ind == n-1){
                return nums[ind];
            }
            if (nums[ind] != nums[ind+1]){
                j = mid-1;
                ans = nums[ind];
            }
            else{
                i = mid+1;
            }
        }
        return ans;
    }
};