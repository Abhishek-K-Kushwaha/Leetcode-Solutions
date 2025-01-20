class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<int> rcnt(m, 0);
        vector<int> ccnt(n, 0);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]){
                    rcnt[i]++;
                    ccnt[j]++;
                }
            }
        }
        vector<vector<int>> ans(m, vector<int> (n));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans[i][j] = 2*rcnt[i]+2*ccnt[j] - m - n;
            }
        }
        return ans;
    }
};