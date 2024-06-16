class Solution {
public:
    void bfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nxt : adj[node]) {
                if (!visited[nxt]) {
                    q.push(nxt);
                    visited[nxt] = 1;
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = connections.size();
        if (cables < n - 1)
            return -1;
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);
        for (auto eg : connections) {
            adj[eg[0]].push_back(eg[1]);
            adj[eg[1]].push_back(eg[0]);
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                components++;
                bfs(i, visited, adj);
            }
        }
        return components - 1;
    }
};