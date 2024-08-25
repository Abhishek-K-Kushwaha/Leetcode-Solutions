class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int l = 0;
        int h  = nums.size() - 1;
        
        
        while(l<h){
            int m = l + (h-l)/2;
            bool isEven = false;
            
            if((h-m)%2 == 0){
                isEven = true; // there are even number of elements present in right side of nums[m]
            }
            else if((h-m)%2 == 1){
                isEven = false; // there are odd number of elements present in right side of nums[m]
            }
            
            if(nums[m] == nums[m+1]){
                if(isEven){
                    l = m + 2;
                }else{
                    h = m - 1;
                }
            }else{
                if(isEven){
                    h = m;
                }else{
                    l = m + 1;
                }
            }
        }
        return nums[l];
    }
};