class Solution {
private:
    int counter;
    bool dfs(int node, bool iscol, vector<bool>& vis, vector<vector<int>>& cords, vector<unordered_set<int>>& adj, vector<bool>& path){ 
        if (path[node]) return true;
        if (vis[node]) return false;
        vis[node] = true;
        path[node] = true;

        if (!adj[node].empty()){
            for (auto nxt : adj[node]){
                if (dfs(nxt, iscol, vis, cords, adj, path)) return true;
            }
        }
        cords[node][iscol] = counter;
        counter--;
        path[node] = false;
        return false;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<unordered_set<int>> adj(k+1);
        vector<bool> vis(k+1, 0);
        vector<vector<int>> cords(k+1, vector<int>(2, -1)); // {i,j} pairs for all nums 1 to k
        counter = k-1;

        for (auto& it: rowConditions){
            adj[it[0]].insert(it[1]);
        }

        for (int node = 1; node <= k; node++){
            vector<bool> path(k+1, 0);
            if (dfs(node, 0, vis, cords, adj, path)) return {}; // for getting rows
        }
        counter = k-1;
        vector<unordered_set<int>> adjcol(k+1);
        //vector<bool> viscol(k+1, 0);
        for (int i = 1; i <=k; i++){
            vis[i] = false;
        }

        for (auto& it: colConditions){
            adjcol[it[0]].insert(it[1]);
        }
        
        for (int node = 1; node <= k; node++){
            vector<bool> path(k+1, 0);
            if (dfs(node, 1, vis, cords, adjcol, path)) return {};// for getting cols
        }

        for (int i = 1; i <= k; i++){
            int r = cords[i][0];
            int c = cords[i][1];
            ans[r][c] = i;
        }
        return ans;        
    }
};