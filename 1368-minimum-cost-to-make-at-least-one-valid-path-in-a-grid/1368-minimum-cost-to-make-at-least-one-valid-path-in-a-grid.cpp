class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // Min-heap {cost, {i, j}}
        vector<vector<int>> costmat(m, vector<int>(n, INT_MAX));
        costmat[0][0] = 0;
        pq.push({0, {0, 0}});
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if (i == m - 1 && j == n - 1) return cost;

            for (int k = 0; k < 4; k++) {
                int newi = i + dx[k];
                int newj = j + dy[k];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
                    int newCost = (k + 1 == grid[i][j]) ? cost : cost + 1;
                    if (newCost < costmat[newi][newj]) {
                        costmat[newi][newj] = newCost;
                        pq.push({newCost, {newi, newj}});
                    }
                }
            }
        }
        return -1;
    }
};