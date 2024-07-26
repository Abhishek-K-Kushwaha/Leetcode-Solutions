class Solution {
public:
    int dijkstra(int src, vector<vector<pair<int, int>>>& adj, int threshold, int n) {
        set<pair<int, int>> st;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        st.insert({0, src});
        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);
            int d = it.first;
            int node = it.second;
            for (auto nxt : adj[node]) {
                int nxtnode = nxt.first;
                int nxtd = nxt.second;
                if (nxtd+d > threshold) continue;
                if (nxtd + d < dist[nxtnode]) {
                    dist[nxtnode] = nxtd + d;
                    st.insert({nxtd + d, nxtnode});
                }
            }
        }
        int cnt = 0;
        for (int d : dist) {
            if (d <= threshold)
                cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto eg : edges) {
            int u = eg[0];
            int v = eg[1];
            int w = eg[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int mincount = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int cnt = dijkstra(i, adj, threshold, n);
            if (cnt <= mincount) {
                ans = i;
                mincount = cnt;
            }
        }
        return ans;
    }
};