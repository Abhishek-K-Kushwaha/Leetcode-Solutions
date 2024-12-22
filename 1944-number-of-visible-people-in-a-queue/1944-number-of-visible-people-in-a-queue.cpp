class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n,0);
        vector<int> stk;
        stk.push_back(heights[n-1]);
        for (int i = n-2; i >= 0; i--){
            while (!stk.empty() && stk.back() < heights[i]){
                ans[i]++;
                stk.pop_back();
            }
            if (!stk.empty())ans[i]++;
            stk.push_back(heights[i]);
        }
        return ans;
    }
};