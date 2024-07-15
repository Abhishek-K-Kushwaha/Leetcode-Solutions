class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        if (n == 1) return {0};
        vector<vector<pair<int,int>>> adj(n); // {nxt node, color} // B = 0 R = 1 
        for (auto& it: redEdges){
            int node = it[0];
            int nxtnode = it[1];
            adj[node].push_back({nxtnode, 1});
        }
        for (auto& it: blueEdges){
            int node = it[0];
            int nxtnode = it[1];
            adj[node].push_back({nxtnode, 0});
        }
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        queue<pair<int,pair<int,int>>> q; // {dist, {node,color of edge}}
        set<pair<int,int>> visited; // {node, color}
        visited.insert({0,-1});
        q.push({0,{ 0, -1}});
        while (!q.empty()){
            auto it = q.front();
            q.pop();
            int d = it.first;
            int node = it.second.first;
            int col = it.second.second;
            for (auto& it: adj[node]){
                int nxtnode = it.first;
                int nxtcol = it.second;
                if (nxtcol != col && visited.find({nxtnode, nxtcol}) == visited.end()){
                    q.push({d+1,{nxtnode, nxtcol}});
                    visited.insert({nxtnode, nxtcol});
                    ans[nxtnode] = min(ans[nxtnode], d+1);
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (ans[i] == INT_MAX) ans[i] = -1;
        }
        return ans;
    }
};