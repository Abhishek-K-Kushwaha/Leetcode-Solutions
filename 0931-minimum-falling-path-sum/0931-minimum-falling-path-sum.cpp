class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev = matrix[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                curr[j] = matrix[i][j];
                if (j == 0)
                    curr[j] += min(prev[j], prev[j + 1]);
                else if (j == n - 1)
                    curr[j] += min(prev[j], prev[j - 1]);
                else
                    curr[j] += min({prev[j - 1], prev[j], prev[j + 1]});
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};