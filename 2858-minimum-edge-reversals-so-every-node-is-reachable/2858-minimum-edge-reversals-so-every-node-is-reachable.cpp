class Solution {
public:
    int to, away, ans;
    void dfs2(int node, vector<vector<pair<int,bool>>>& adj, vector<int>& res){
        for (auto [nxt,sign]:adj[node]){
            if (res[nxt] == -1){
                // if (!sign) to++;
                // else away++;
                to += (!sign);
                away += sign;
                res[nxt] = res[0]+away-to;
                dfs2(nxt, adj, res);
                // if (!sign) to--;
                // else away--;
                to -= (!sign);
                away -= sign;
            }
        }
    }
    void dfs(int node, vector<vector<pair<int,bool>>>& adj, int parent){
        for (auto [nxt,sign]:adj[node]){
            if (nxt != parent){
                if (!sign) {
                    to++;
                }
                dfs(nxt, adj, node);
            }
        }
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
        to =  0;
        dfs(0, adj, -1);
        res[0] = to;
        to = 0, away = 0;
        dfs2(0, adj, res);
        return res;
    }
};