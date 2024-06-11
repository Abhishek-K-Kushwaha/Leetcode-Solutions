class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        st.insert({0, {0, 0}});
        vector<int> delx = {0, 0, -1, 1};
        vector<int> dely = {1, -1, 0, 0};
        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);
            int maxdiff = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if (x == n - 1 && y == m - 1)
                return maxdiff;
            for (int i = 0; i < 4; i++) {
                int newx = x + delx[i];
                int newy = y + dely[i];
                if (newx >= 0 && newy >= 0 && newx < n && newy < m) {
                    int diff = abs(heights[x][y] - heights[newx][newy]);
                    int neweffort = max(diff, maxdiff);
                    if (neweffort < effort[newx][newy]) {
                        effort[newx][newy] = neweffort;
                        st.insert({neweffort, {newx, newy}});
                    }
                }
            }
        }
        return -1;
    }
};