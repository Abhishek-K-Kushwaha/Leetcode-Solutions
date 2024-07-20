class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        int r = 0, c = 0;
        while (r < m || c < n){
            if (r == m){
                ans[r-1][c] = colSum[c];
                c++;
                continue;
            }
            if (c == n){
                ans[r][c-1] = rowSum[r];
                r++;
                continue;
            }
            int val = min(rowSum[r], colSum[c]);
            rowSum[r] -= val;
            colSum[c] -= val;
            ans[r][c] = val;

            if (rowSum[r] == 0) r++;
            if (colSum[c] == 0) c++;
        }
        return ans;
    }
};