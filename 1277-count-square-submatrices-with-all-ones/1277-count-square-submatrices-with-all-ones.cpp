class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0);
        vector<int> curr(m);
        int cnt = 0;
        for (int r = 0; r < n; r++){
            for (int c = 0; c < m; c++){
                curr[c] = 0;
                if (r == 0 || c == 0){ 
                    curr[c] = matrix[r][c];
                }
                else if (matrix[r][c]){
                    curr[c] = 1 + min({curr[c-1], prev[c-1], prev[c]});
                }
                cnt += curr[c];
            }
            prev = curr;
        }
        return cnt;
    }
};