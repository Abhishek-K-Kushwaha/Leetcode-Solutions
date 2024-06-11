class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto eg : flights) {
            adj[eg[0]].push_back({eg[1], eg[2]});
        }
        queue<pair<int, pair<int, int>>> q; //{stops,{node,cost}}
        vector<int> cost(n, INT_MAX);
        q.push({0, {src, 0}});
        cost[src] = 0;
        while (!q.empty()) {
            int stp = q.front().first;
            int node = q.front().second.first;
            int cst = q.front().second.second;
            q.pop();
            if (stp > k)
                continue;
            for (auto nxt : adj[node]) {
                int nxtnode = nxt.first;
                int nxtcst = nxt.second;
                if (nxtcst + cst < cost[nxtnode]) {
                    cost[nxtnode] = nxtcst + cst;
                    q.push({stp + 1, {nxtnode, nxtcst + cst}});
                }
            }
        }

        if (cost[dst] == INT_MAX)
            return -1;
        else
            return cost[dst];
    }
};