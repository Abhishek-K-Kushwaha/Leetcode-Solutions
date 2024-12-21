class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // Build adjacency list with edge directions
        vector<vector<pair<int,int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], 0);  // 0 for forward edge
            adj[edge[1]].emplace_back(edge[0], 1);  // 1 for reverse edge
        }
        
        vector<int> result(n);
        
        // First DFS from node 0 to compute base costs
        int total_reversals = dfs1(0, -1, adj);
        result[0] = total_reversals;
        
        // Second DFS to compute costs for all other nodes
        dfs2(0, -1, total_reversals, adj, result);
        
        return result;
    }
    
private:
    int dfs1(int node, int parent, const vector<vector<pair<int,int>>>& adj) {
        int reversals = 0;
        for (const auto& [next, isReverse] : adj[node]) {
            if (next != parent) {
                reversals += isReverse + dfs1(next, node, adj);
            }
        }
        return reversals;
    }
    
    void dfs2(int node, int parent, int parentCost, const vector<vector<pair<int,int>>>& adj, vector<int>& result) {
        for (const auto& [next, isReverse] : adj[node]) {
            if (next != parent) {
                // If edge was forward (0), it becomes reverse (1) when changing root
                // If edge was reverse (1), it becomes forward (0) when changing root
                int newCost = parentCost + (isReverse == 0 ? 1 : -1);
                result[next] = newCost;
                dfs2(next, node, newCost, adj, result);
            }
        }
    }
};