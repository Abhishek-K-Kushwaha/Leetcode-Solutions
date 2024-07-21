class Solution {
private:
    int counter;
    bool dfs(int node, bool iscol, vector<bool>& vis, vector<int>& cords, vector<unordered_set<int>>& adj, vector<bool>& path, vector<vector<int>>& ans){ 
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
        vector<unordered_set<int>> adj(k+1);
        vector<bool> vis(k+1, 0);
        vector<int> cords(k+1); // stores rows for all nums 1 to k
        counter = k-1;

        for (auto& it: rowConditions){
            adj[it[0]].insert(it[1]);
        }

        vector<bool> path(k+1, 0);
        for (int node = 1; node <= k; node++){
            if (dfs(node, 0, vis, cords, adj, path, ans)) return {}; // for getting rows
        }

        counter = k-1;
        for (int i = 1; i <=k; i++){
            vis[i] = false;
            adj[i].clear();
        }

        for (auto& it: colConditions){
            adj[it[0]].insert(it[1]);
        }
        
        for (int node = 1; node <= k; node++){
            if (dfs(node, 1, vis, cords, adj, path, ans)) return {}; // for getting cols
        }

        return ans;        
    }
};