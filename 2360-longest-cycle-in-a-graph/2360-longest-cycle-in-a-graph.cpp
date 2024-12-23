class Solution {
public:
    int ans = 0;
    int d;
    void dfs(int node, vector<int>& edges, unordered_map<int,int>& pathvis, 
    vector<int>& vis){
        vis[node] = 1;
        pathvis[node] = d;
        int nxt = edges[node];
        if (pathvis.find(nxt) != pathvis.end()){
            ans = max(ans, d - pathvis[nxt] + 1);
            return;
        }
        if (nxt == -1 || vis[nxt]) return;
        d++;
        dfs(nxt, edges, pathvis, vis);
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n,0);
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                unordered_map<int,int> pathvis;
                d = 1;
                dfs(i, edges, pathvis, vis);
            }
        }
        if (ans) return ans;
        return -1;
    }
};