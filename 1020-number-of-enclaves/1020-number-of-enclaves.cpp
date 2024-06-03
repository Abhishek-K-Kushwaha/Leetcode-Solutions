class Solution {
public:
    int bfs(int m, int n, queue<pair<int, int>>& q, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        int count = 0;
        vector<int> delx = {0, 0, -1, 1};
        vector<int> dely = {-1, 1, 0, 0};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            count++;
            for (int i = 0; i < 4; i++) {
                int newx = x + delx[i];
                int newy = y + dely[i];
                if (newx >= 0 && newy >= 0 && newx < m && newy < n &&
                    grid[newx][newy] == 1 && visited[newx][newy] == 0) {
                    q.push({newx, newy});
                    visited[newx][newy] = 1; 
                }
            }
        }
        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    if (row == 0 || row == m - 1 || col == 0 || col == n - 1) {
                        q.push({row,col});
                        visited[row][col] = 1;
                    }
                    count++;
                }
            }
        }
        count -= bfs(m, n, q, visited, grid);
        return count;
    }
};