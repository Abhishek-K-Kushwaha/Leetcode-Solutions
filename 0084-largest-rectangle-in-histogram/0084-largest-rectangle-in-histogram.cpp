class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            while (!stk.empty() &&
                   (i == n || heights[stk.top()] > heights[i])) {
                int h = heights[stk.top()];
                stk.pop();
                int w;
                if (stk.empty())
                    w = i;
                else
                    w = i - stk.top() - 1;
                ans = max(ans, h * w);
            }
            stk.push(i);
        }
        return ans;
    }
};