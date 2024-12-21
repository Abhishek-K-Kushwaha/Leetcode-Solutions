class Solution {
public:
    int to, away, ans;
    bool dfs(int node, vector<vector<pair<int,bool>>>& adj, int parent, vector<int>& res){
        if (res[node] != -1){
            ans = res[node] + to - away;
            return true;
        }
        for (auto [nxt,sign]:adj[node]){
            if (nxt != parent){
                if (!sign) {
                    to++;
                }
                else{
                    away++;
                }
                if (dfs(nxt, adj, node, res)) return true;
                if (res[0] != -1 ){ 
                    if (!sign) to--;
                    else away--;
                }
            }
        }
        return false;
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,bool>>> adj(n);
        int a, b;
        for (auto it: edges){
            a = it[0], b = it[1];
            adj[a].push_back({b,1});
            adj[b].push_back({a,0});
        }
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++){
            ans = 0;
            to = 0, away = 0;
            if (dfs(i, adj, -1, res)) res[i] = ans;
            else res[i] = to;
        }
        return res;
    }
};