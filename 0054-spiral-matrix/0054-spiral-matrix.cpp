class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        int count = 0;
        vector<int> ans;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
                count += 1;
            }
            top++;
            if (count == m * n)
                break;
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
                count += 1;
            }
            right--;
            if (count == m * n)
                break;
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
                count += 1;
            }
            bottom--;
            if (count == m * n)
                break;
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
                count += 1;
            }
            left++;
            if (count == m * n)
                break;
        }
        return ans;
    }
};