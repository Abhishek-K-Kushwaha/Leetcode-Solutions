class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        cost[0][0] = 0;
        dq.push_front({0, 0});
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();
            
            for (int k = 0; k < 4; ++k) {
                int newi = i + dx[k];
                int newj = j + dy[k];
                
                if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
                    int newCost = cost[i][j] + (grid[i][j] != k + 1);
                    
                    if (newCost < cost[newi][newj]) {
                        cost[newi][newj] = newCost;
                        if (grid[i][j] == k + 1) {
                            dq.push_front({newi, newj});
                        } else {
                            dq.push_back({newi, newj});
                        }
                    }
                }
            }
        }
        return cost[m - 1][n - 1];
    }
};