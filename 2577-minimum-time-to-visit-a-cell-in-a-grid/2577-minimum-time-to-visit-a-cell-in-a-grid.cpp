class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; //{time{x,y}}
        vector<vector<int>> time(m, vector<int>(n, INT_MAX));
        time[0][0] = 0;
        if (grid[0][1] <= 1) {
            pq.push({1, {0, 1}});
            time[0][1] = 1;
            if (grid[1][0] % 2) {
                pq.push({grid[1][0], {1, 0}});
                time[1][0] = grid[1][0];
            } else {
                pq.push({grid[1][0] + 1, {1, 0}});
                time[1][0] = grid[1][0] + 1;
            }
        } else if (grid[1][0] <= 1) {
            pq.push({1, {1, 0}});
            time[1][0] = 1;
            if (grid[0][1] % 2) {
                pq.push({grid[0][1], {0, 1}});
                time[0][1] = grid[0][1];
            } else {
                pq.push({grid[0][1] + 1, {0, 1}});
                time[0][1] = grid[0][1] + 1;
            }
        }
        vector<int> delx = {0, 0, -1, 1};
        vector<int> dely = {-1, 1, 0, 0};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if (x == m - 1 && y == n - 1)
                return t;
            for (int i = 0; i < 4; i++) {
                int newx = x + delx[i];
                int newy = y + dely[i];
                if (newx >= 0 && newx < m && newy >= 0 && newy < n && time[newx][newy] == INT_MAX) {
                    if (grid[newx][newy] <= t + 1) {
                        if (time[newx][newy] > t + 1)
                            pq.push({t + 1, {newx, newy}});
                        time[newx][newy] = t + 1;
                    } else {
                        int diff = grid[newx][newy] - t;
                        int newt = t;
                        if (diff % 2 == 0)
                            newt += (diff + 1);
                        else
                            newt += diff;
                        if (time[newx][newy] > newt)
                            pq.push({newt, {newx, newy}});
                        time[newx][newy] = newt;
                    }
                }
            }
        }
        return -1;
    }
};