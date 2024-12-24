class Solution {
public:
    int dia = 0;
    int d = 0;
    int dfs(int node, int par, vector<vector<int>>& adj){
        int maxd = 0, temp;
        for (int nxt:adj[node]){
            if (nxt != par){
                d++;
                temp = dfs(nxt, node, adj);
                d--;
                dia = max(dia, maxd-d + temp-d);
                maxd = max(maxd, temp);
            }
        }
        dia = max(dia, d);
        return max(maxd, d);
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size(), m = edges2.size();
        vector<vector<int>> adj1(n+1);
        for (auto& it: edges1){
            adj1[it[0]].emplace_back(it[1]);
            adj1[it[1]].emplace_back(it[0]);
        }
        dfs(0, -1, adj1);
        int dia1 = dia;
        vector<vector<int>> adj2(m+1);
        for (auto& it: edges2){
            adj2[it[0]].emplace_back(it[1]);
            adj2[it[1]].emplace_back(it[0]);
        }
        d = 0;
        dia = 0;
        dfs(0, -1, adj2);
        int dia2 = dia;
        int ans = (dia1+1)/2 + (dia2+1)/2 + 1;
        ans = max(ans, dia1);
        ans = max(ans, dia2);
        return ans;
    }
};