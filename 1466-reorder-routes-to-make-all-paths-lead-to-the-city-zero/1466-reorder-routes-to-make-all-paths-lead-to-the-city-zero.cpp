class Solution {
public:
    int dfs(vector<vector<int>> &al, int parent, int from) {
        auto change = 0;
        for (auto to : al[from])
            if (abs(to) != parent)
                change += dfs(al, abs(from), abs(to)) + (to > 0);
        return change;        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> al(n);
        for (auto &c : connections) {
            al[c[0]].emplace_back(c[1]);
            al[c[1]].emplace_back(-c[0]);
        }
        return dfs(al, -1, 0);
    }
};