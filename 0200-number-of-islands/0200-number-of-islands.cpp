class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        int cnt = 0;
        vector<int> delx = {0,0,1,-1};
        vector<int> dely = {-1,1,0,0};
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && visited[i][j] == 0){
                    cnt++;
                    q.push({i,j});
                    visited[i][j] = 1;
                    //bfs(q,visited);
                    while (!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int nxt = 0; nxt < 4; nxt++){
                            int newx = x + delx[nxt];
                            int newy = y + dely[nxt];
                            if (newx >= 0 && newy >= 0 && newx < m && newy < n && visited[newx][newy] == 0 && grid[newx][newy] == '1'){
                                visited[newx][newy] = 1;
                                q.push({newx,newy});
                            }
                        }

                    }

                }
            }
        }
        return cnt;
    }
};