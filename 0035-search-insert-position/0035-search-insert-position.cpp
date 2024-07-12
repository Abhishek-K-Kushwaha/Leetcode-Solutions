class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0; 
        int j = n-1;
        while (i <= j){
            int mid = i + (j - i)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target){
                i = mid + 1;
            }
            else{
                j = mid - 1;
            }
        }

        return i;
    }
};