class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowdata(m, INT_MAX);
        vector<int> coldata(n, INT_MIN);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                rowdata[i] = min(rowdata[i], matrix[i][j]);
                coldata[j] = max(coldata[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == rowdata[i] && matrix[i][j] == coldata[j]) ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};