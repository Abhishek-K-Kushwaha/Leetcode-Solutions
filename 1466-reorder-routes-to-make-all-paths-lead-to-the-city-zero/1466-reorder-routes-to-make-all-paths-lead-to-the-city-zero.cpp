class Solution {
public:
    void dfs(int node, vector<vector<pair<int, bool>>>& adj, int& ans,
             int parent) {
        for (auto& [nxt, sign] : adj[node]) {
            if (nxt != parent) {
                ans += sign;
                dfs(nxt, adj, ans, node);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, bool>>> adj(n);
        int a, b;
        for (auto it : edges) {
            a = it[0], b = it[1];
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }
        int ans = 0;
        dfs(0, adj, ans, -1);
        return ans;
    }
};