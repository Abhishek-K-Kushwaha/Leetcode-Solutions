class Solution {
public:
int f(int row, int col1, int col2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return INT_MIN;
        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];
        if (n-1 == row) {
            if (col1 != col2) return dp[row][col1][col2]  = grid[row][col1] + grid[row][col2];
            else return dp[row][col1][col2]  = grid[row][col1];
        }
        int maxval = 0;
        for (int d1 = -1; d1 <= 1; d1++){
            for (int d2 = -1; d2 <= 1; d2++){
                int newcol1 = col1 + d1;
                int newcol2 = col2 + d2;
                int val = f(row+1,newcol1,newcol2,n,m,grid,dp);
                if (col1 != col2) val += grid[row][col1] + grid[row][col2] ;
                else val += grid[row][col1];
                maxval = max(maxval,val);
            }
        }
        return dp[row][col1][col2]  = maxval;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0, m-1,n,m,grid,dp); 
    }
};