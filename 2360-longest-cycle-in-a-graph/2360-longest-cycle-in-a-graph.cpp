class Solution {
public:
    int ans = 0;
    int d;
    void dfs(int node, vector<int>& edges, vector<int>& pathvis){
        pathvis[node] = d;
        int nxt = edges[node];
        if (nxt != -1 && pathvis[nxt] > 1){
            ans = max(ans, d - pathvis[nxt] + 1);
            pathvis[node]=1;
            return;
        }
        if (nxt == -1 || pathvis[nxt]){ 
            pathvis[node]=1;
            return;
        }
        d++;
        dfs(nxt, edges, pathvis);
        pathvis[node]=1;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> pathvis(n,0);
        for (int i = 0; i < n; i++){
            if (!pathvis[i]){
                d = 2;
                dfs(i, edges, pathvis);
            }
        }
        if (ans) return ans;
        return -1;
    }
};