class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (n == 2) return (nums[0] < nums[1]);
        int i = 0;
        int j = n-1;
        while (i <= j){
            if (j - i == 1) return i + (nums[i] < nums[j]);
            int mid = i + (j - i)/2;
            //cout<< mid << " ";
            if (mid == 0 && nums[mid+1] < nums[mid]){
                return mid;
            }
            if (mid == n-1 && nums[mid-1] < nums[mid]){
                return mid;
            }
            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
            if (nums[mid-1] > nums[mid]) j = mid-1;
            else i = mid + 1;
        }
        return -1;
    }
};