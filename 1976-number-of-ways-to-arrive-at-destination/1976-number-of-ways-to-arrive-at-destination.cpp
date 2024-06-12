class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto eg : roads) {
            int u = eg[0];
            int v = eg[1];
            int w = eg[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        set<pair<long long, int>> st; //{distance,node}
        st.insert({0, 0});
        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);
            long long d = it.first;
            int node = it.second;
            int w = ways[node];
            for (auto nxt : adj[node]) {
                int nxtnode = nxt.first;
                long long nxtd = nxt.second;
                if (nxtd + d == dist[nxtnode]) {
                    ways[nxtnode] += w;
                    ways[nxtnode] %= mod;
                } else if (nxtd + d < dist[nxtnode]) {
                    ways[nxtnode] = (w % mod);
                    dist[nxtnode] = d + nxtd;
                    st.insert({d + nxtd, nxtnode});
                }
            }
        }
        return ways[n - 1];
    }
};