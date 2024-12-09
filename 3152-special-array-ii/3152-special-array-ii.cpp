class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> subarr(n);
        subarr[0] = 1;
        for (int i = 1; i < n; i++){
            if ((nums[i]+nums[i-1])%2){
                subarr[i] = subarr[i-1];
            }
            else subarr[i] = subarr[i-1]+1;
        }
        int m = queries.size();
        vector<bool> ans(m);
        int i = 0;
        for (auto it:queries){
            if (subarr[it[0]]==subarr[it[1]]) ans[i] = (true);
            else ans[i] = (false);
            i++;
        }
        return ans;
    }
};