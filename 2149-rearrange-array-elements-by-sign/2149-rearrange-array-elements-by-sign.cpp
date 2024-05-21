class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        int pos = 0;
        int neg = 0;
        vector<int> ans;
        while(count != len){
            if (count%2 == 0){
                while(nums[pos] < 0){
                    pos++;
                }
                ans.push_back(nums[pos]);
                pos++;
                count++;
            }
            else{
                while(nums[neg] > 0){
                    neg++;
                }
                ans.push_back(nums[neg]);
                neg++;
                count++;
            }
        }
        return ans;
    }
};