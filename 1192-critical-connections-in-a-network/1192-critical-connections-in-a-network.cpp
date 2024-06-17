class Solution {
private:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& visited,
             vector<vector<int>>& ans, vector<vector<int>>& adj,
             vector<int>& tin, vector<int>& tlow) {
        visited[node] = 1;
        tin[node] = tlow[node] = timer;
        timer++;
        for (auto nxt : adj[node]) {
            if (nxt != parent) {
                if (!visited[nxt]) {
                    dfs(nxt, node, visited, ans, adj, tin, tlow);
                    tlow[node] = min(tlow[node], tlow[nxt]);
                    if (tlow[nxt] > tin[node]) {
                        ans.push_back({node, nxt});
                    }
                } else {
                    tlow[node] = min(tlow[node], tlow[nxt]);
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto eg : connections) {
            adj[eg[0]].push_back(eg[1]);
            adj[eg[1]].push_back(eg[0]);
        }
        vector<int> visited(n, 0);
        vector<int> tin(n);
        vector<int> tlow(n);
        vector<vector<int>> ans;
        dfs(0, -1, visited, ans, adj, tin, tlow);
        return ans;
    }
};