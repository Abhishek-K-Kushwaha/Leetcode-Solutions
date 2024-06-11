class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();
        if (grid[n-1][n-1] == 1)
            return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int d = dist[x][y];
            vector<int> delx = {0, 0, 1, -1, 1, 1, -1, -1};
            vector<int> dely = {-1, 1, 0, 0, -1, 1, 1, -1};
            for (int i = 0; i < 8; i++) {
                int newx = x + delx[i];
                int newy = y + dely[i];
                if (newx >= 0 && newy >= 0 && newx < n && newy < n &&
                    grid[newx][newy] == 0 && dist[newx][newy] > d + 1) {
                    dist[newx][newy] = d + 1;
                    q.push({newx, newy});
                }
            }
        }
        if (dist[n - 1][n - 1] == INT_MAX)
            return -1;
        else
            return dist[n - 1][n - 1];
    }
};