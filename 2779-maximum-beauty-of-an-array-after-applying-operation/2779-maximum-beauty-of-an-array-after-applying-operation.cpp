class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1, r = n, mid;
        while (l < r){
            mid = (l+r+1)/2;
            //cout<< mid <<endl;
            for (int i = mid-1; i < n; i++){
                if (nums[i] - nums[i-mid+1] <= 2*k){
                    l = mid;
                    break;
                }
            }
            if (l != mid) r = mid-1;
        }
        return l;
    }
};