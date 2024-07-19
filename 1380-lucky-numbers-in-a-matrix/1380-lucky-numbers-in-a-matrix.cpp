class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int minele = INT_MAX;
            pair<int, int> cord;
            for (int j = 0; j < n; j++) {
                if (minele > matrix[i][j]) {
                    minele = matrix[i][j];
                    cord = {i, j};
                }
            }
            int flag = 1;
            for (int row = 0; row < m; row++) {
                if (minele < matrix[row][cord.second]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ans.push_back(matrix[cord.first][cord.second]);
                break;
            }
        }
        return ans;
    }
};