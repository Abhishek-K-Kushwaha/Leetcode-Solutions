class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<vector<int>>& edges, set<pair<int,int>>& st, int& ans, int parent){
        for (int nxt:adj[node]){
            if (nxt != parent){
                if (st.find({node, nxt}) != st.end()) ans++;
                dfs(nxt, adj, edges, st, ans, node);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        set<pair<int,int>> st;
        int a, b;
        for (auto it: edges){
            a = it[0], b = it[1];
            st.insert({a,b});
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;
        //vector<int> res(n);
        //for (int i = 0; i < n; i++){
            //ans = 0;
        dfs(0, adj, edges, st, ans, -1);
            //res[i] = ans;
        //}
        return ans;
    }
};