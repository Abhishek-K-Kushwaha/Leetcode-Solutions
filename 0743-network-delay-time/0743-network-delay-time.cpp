class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        set<pair<int, int>> st; //{time,node}
        vector<int> time(n + 1, INT_MAX);
        st.insert({0, k});
        time[k] = 0;
        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);
            int t = it.first;
            int node = it.second;
            for (auto nxt : adj[node]) {
                int nxtnode = nxt.first;
                int nxttime = nxt.second;
                if (nxttime + t < time[nxtnode]) {
                    time[nxtnode] = nxttime + t;
                    st.insert({nxttime + t, nxtnode});
                }
            }
        }
        int maxtime = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (time[i] == INT_MAX)
                return -1;
            maxtime = max(maxtime, time[i]);
        }
        return maxtime;
    }
};