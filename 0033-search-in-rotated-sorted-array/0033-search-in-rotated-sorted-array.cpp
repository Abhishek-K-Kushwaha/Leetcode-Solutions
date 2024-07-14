class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1){
            if (nums[0] == target) return 0;
            else return -1;
        }
        if (n == 2){
            if (nums[0] == target) return 0;
            if (nums[1] == target) return 1;
            else return -1;
        }
        int pivot = -1;
        if (nums[0] > nums[n-1]){
            int i = 0;
            int j = n-1;
            while (i <= j){
                int mid = i + (j-i)/2;
                if (nums[mid] == target) return mid;
                if (nums[mid] > nums[mid+1]){ 
                    pivot = mid;
                    break;
                }
                if (nums[mid] > nums[n-1]) i = mid+1;
                else j = mid-1;
            }
        }
        if (pivot == -1){
            int i = 0;
            int j = n-1;
            while (i <= j){
                int mid = i + (j-i)/2;
                if (nums[mid] == target){ 
                    return mid;
                }
                if (nums[mid] > target) j = mid-1;
                else i = mid+1;
            }
            return -1;
        }
        if (target < nums[0]){
            int i = pivot+1;
            int j = n-1;
            while (i <= j){
                int mid = i + (j-i)/2;
                if (nums[mid] == target){ 
                    return mid;
                }
                if (nums[mid] > target) j = mid-1;
                else i = mid+1;
            }
            return -1;
        }
        else{
            int i = 0;
            int j = pivot;
            while (i <= j){
                int mid = i + (j-i)/2;
                if (nums[mid] == target){ 
                    return mid;
                }
                if (nums[mid] > target) j = mid-1;
                else i = mid+1;
            }
            return -1;
        }
        return -1;
    }
};