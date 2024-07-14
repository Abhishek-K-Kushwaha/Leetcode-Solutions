class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        int left = -1;
        int right = -1;
        int i = 0;
        int j = n-1;
        if (nums[0] == target){ 
            left = 0;
            j = -1;
        }
        while (i <= j){
            int mid = i + (j-i)/2;
            if (nums[mid] == target){
                if (nums[mid-1] < nums[mid]){ 
                    left = mid;
                    break;
                }
                else j = mid-1;
            }
            else if (nums[mid] > target) j = mid-1;
            else i = mid+1;
        }
        i = 0;
        j = n-1;
        if (nums[n-1] == target){ 
            right = n-1;
            j = -1;
        }
        while (i <= j){
            int mid = i + (j-i)/2;
            if (nums[mid] == target){
                if (nums[mid+1] > nums[mid]){ 
                    right = mid;
                    break;
                }
                else i = mid+1;
            }
            else if (nums[mid] > target) j = mid-1;
            else i = mid+1;
        }
        return {left, right};
    }
};