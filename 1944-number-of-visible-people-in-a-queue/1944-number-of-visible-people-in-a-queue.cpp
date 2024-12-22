class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n,0);
        stack<int> stk;
        stk.push(heights[n-1]);
        for (int i = n-2; i >= 0; i--){
            while (!stk.empty() && stk.top() < heights[i]){
                ans[i]++;
                stk.pop();
            }
            if (!stk.empty())ans[i]++;
            stk.push(heights[i]);
        }
        return ans;
    }
};