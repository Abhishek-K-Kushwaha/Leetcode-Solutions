class Solution {
public:
    int tot = 0, n, m;
    int dfs(int x, int y, vector<pair<int,int>>&d, vector<vector<bool>>&vis, vector<vector<int>>& grid, int cnt){
        if (grid[x][y] == 2){
            //cout<< cnt<< endl;
            if (cnt == tot+1) return 1;
            else return 0;
        }
        int ans = 0;
        vis[x][y] = true;
        cnt++;
        for (int i = 0; i < 4; i++){
            int nx = x + d[i].first;
            int ny = y + d[i].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                    !vis[nx][ny] && grid[nx][ny] != -1){
                ans += dfs(nx, ny, d, vis, grid, cnt);
            }
        }
        vis[x][y] = false;
        cnt--;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int stx, sty;
        for (int r = 0; r < n; r++){
            for (int c = 0; c < m; c++){
                if (grid[r][c] == 1){
                    stx = r;
                    sty = c;
                }
                else if (grid[r][c] == 0) tot++;
            }
        }
        //cout<<"tot= "<< tot<<endl;
        return dfs(stx, sty, d, vis, grid, 0);
    }
};