class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> outdegree(V);
        vector<vector<int>> revadj(V);
        for (int i = 0; i < V; i++) {
            for (int node : adj[i]) {
                revadj[node].push_back(i);
                outdegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nxt : revadj[node]) {
                outdegree[nxt]--;
                if (outdegree[nxt] == 0)
                    q.push(nxt);
            }
            ans.push_back(node);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};