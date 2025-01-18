class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dr = {0, 0, 0, 1, -1};
        vector<int> dc = {0, 1, -1, 0, 0};
        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        dis[0][0] = 0;
        while (!dq.empty()) {
            int r = dq.front().first;
            int c = dq.front().second;
            if (r == m - 1 && c == n - 1)
                return dis[r][c];
            dq.pop_front();
            for (int i = 1; i < 5; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc < n && nc >= 0) {
                    if (grid[r][c] == i && dis[nr][nc] > dis[r][c]) {
                        dis[nr][nc] = dis[r][c];
                        dq.push_front({nr, nc});
                    } else if (dis[nr][nc] > dis[r][c] + 1) {
                        dis[nr][nc] = dis[r][c] + 1;
                        dq.push_back({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};