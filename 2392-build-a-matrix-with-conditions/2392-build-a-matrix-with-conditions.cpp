class Solution {
private:
    int counter;
    bool dfs(int node, bool iscol, vector<bool>& vis, vector<int>& cords, vector<vector<int>>& adj, vector<bool>& path, vector<vector<int>>& ans){ 
        if (path[node]) return true;
        if (vis[node]) return false;
        vis[node] = true;
        path[node] = true;

        for (auto nxt : adj[node]){
            if (dfs(nxt, iscol, vis, cords, adj, path, ans)) return true;
        }

        if (iscol) ans[cords[node]][counter] = node;
        else cords[node] = counter;
        counter--;
        path[node] = false;
        return false;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<vector<int>> adj_row(k+1), adj_col(k+1);
        vector<bool> vis(k+1, 0);
        vector<int> cords(k+1); // stores rows for all nums 1 to k
        vector<bool> path(k+1, 0);
        
        // Build adjacency list for row conditions
        for (auto& it: rowConditions){
            adj_row[it[0]].push_back(it[1]);
        }

        counter = k-1;
        for (int node = 1; node <= k; node++){
            if (dfs(node, false, vis, cords, adj_row, path, ans)) return {}; // for getting rows
        }

        // Reset for column conditions
        fill(vis.begin(), vis.end(), false);
        //fill(path.begin(), path.end(), false);
        counter = k-1;

        // Build adjacency list for column conditions
        for (auto& it: colConditions){
            adj_col[it[0]].push_back(it[1]);
        }
        
        for (int node = 1; node <= k; node++){
            if (dfs(node, true, vis, cords, adj_col, path, ans)) return {}; // for getting cols
        }

        return ans;        
    }
};
