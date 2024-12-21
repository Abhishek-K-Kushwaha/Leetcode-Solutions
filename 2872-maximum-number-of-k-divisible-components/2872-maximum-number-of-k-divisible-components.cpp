class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& val, int k){
        int ans = 0;
        for (auto it:adj[node]){
            if (it != parent){
                ans += dfs(it, node, adj, val, k);
            }
        }
        int rem = val[node] % k;
        if (rem) val[parent] += rem;
        else ans++;
        return ans;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& val, int k) {
        vector<vector<int>> adj(n);
        for (auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(0, -1, adj, val, k);
    }
};