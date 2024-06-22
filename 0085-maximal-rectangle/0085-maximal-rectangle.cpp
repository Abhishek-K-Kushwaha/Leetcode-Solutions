class Solution {
public:
    int largestRectangleInHistogram(vector<int>& heights, int n) {
        //int n = heights.size();
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            while (!stk.empty() &&
                   (i == n || heights[stk.top()] >= heights[i])) {
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int ans = 0;
        for (int r = 0; r < n; r++){
            for (int c = 0; c < m; c++){
                if (matrix[r][c] == '1') heights[c]++;
                else heights[c] = 0;
            }
            int val = largestRectangleInHistogram(heights, m);
            ans = max(ans, val);
        }
        return ans;
    }
};