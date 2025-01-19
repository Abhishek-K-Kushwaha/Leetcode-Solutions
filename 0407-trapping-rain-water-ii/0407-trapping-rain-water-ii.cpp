class Solution {
public:
    int trapRainWater(vector<vector<int>>& hmap) {
        int m = hmap.size();
        int n = hmap[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        set<pair<int, int>> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    vis[i][j] = 1;
                    st.insert({hmap[i][j], i * n + j});
                }
            }
        }
        int node, h, r, c, nc, nr, ans = 0;
        vector<int> dr = {1, -1, 0, 0}, dc = {0, 0, 1, -1};
        while (!st.empty()) {
            auto it = st.begin();
            h = (*it).first;
            node = (*it).second;
            st.erase(it);
            r = node / n;
            c = node % n;
            for (int i = 0; i < 4; i++) {
                nr = r + dr[i];
                nc = c + dc[i];
                if (nr > 0 && nr < m && nc > 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    if (hmap[nr][nc] < h) {
                        ans += (h - hmap[nr][nc]);
                        st.insert({h, nr * n + nc});
                    } else
                        st.insert({hmap[nr][nc], nr * n + nc});
                }
            }
        }
        return ans;
    }
};

// ind => i*n + j
// i = ind / n
// j = ind % n