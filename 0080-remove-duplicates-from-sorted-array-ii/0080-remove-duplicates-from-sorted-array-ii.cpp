class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int i = 1;
        int cnt = 1;
        for (int j = 1; j < n; j++){
            if (nums[j] == nums[j-1]){
                cnt++;
                if (cnt <= 2){
                    nums[i] = nums[j];
                    i++;
                }
            }
            else{
                cnt = 1;
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};