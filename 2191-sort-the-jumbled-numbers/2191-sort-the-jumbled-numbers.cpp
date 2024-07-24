class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        using int2 = pair<int,int>;
        int n = nums.size();
        vector<int2> vals(n); // {ind, val}
        int ind = 0;
        for (int num:nums){
            int org = num;
            if (org == 0){
                vals[ind] = {mapping[0], ind};
                ind++;
                continue;
            }
            int val = 0;
            int i = 1;
            while(num){
                int r = num % 10;
                num /= 10;
                val += mapping[r] * i;
                i *= 10;
            }
            vals[ind] = {val, ind};
            ind++;
        }
        sort(vals.begin(), vals.end());
        vector<int> ans(n);
        ind = 0;
        for (auto& it: vals){
            ans[ind] = (nums[it.second]);
            ind++;
        }
        return ans;
    }
};