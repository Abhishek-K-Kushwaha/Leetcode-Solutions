class Solution {
public:
    int trapRainWater(vector<vector<int>>& hmap) {
        int m = hmap.size();
        int n = hmap[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        set<pair<int, int>> st;
        for (int i = 0; i < m; i++) {
            vis[i][0] = 1;
            st.insert({hmap[i][0], i * n });
        }
        for (int i = 0; i < m; i++) {
            vis[i][n-1] = 1;
            st.insert({hmap[i][n-1], i * n + n-1});
        }
        for (int i = 0; i < n; i++) {
            vis[0][i] = 1;
            st.insert({hmap[0][i], 0 * n + i});
        }
        for (int i = 0; i < n; i++) {
            vis[m-1][i] = 1;
            st.insert({hmap[m-1][i], (m-1)* n + i});
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