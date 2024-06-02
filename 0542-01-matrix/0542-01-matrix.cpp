class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1)); // distance matrix initialized to -1
        queue<pair<int, int>> q;    // queue to store coordinates

        // Traverse the matrix to initialize queue and distance matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0; // distance to itself is zero
                }
            }
        }

        // Direction vectors for moving up, right, down, left
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Check all four possible directions
            for (int i = 0; i < 4; ++i) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                // Check if new position is within bounds and not yet visited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    dist[newRow][newCol] == -1) {
                    dist[newRow][newCol] =
                        dist[row][col] + 1;   // update distance
                    q.push({newRow, newCol}); // add new position to queue
                }
            }
        }

        return dist;
    }
};