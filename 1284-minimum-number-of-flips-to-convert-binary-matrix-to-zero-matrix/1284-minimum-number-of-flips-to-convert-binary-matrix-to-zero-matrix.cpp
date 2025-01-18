class Solution {
public:
    int m, n;
    int f(int node, vector<vector<int>> mat) {
        bool done = true;
        for (auto& it : mat) {
            for (int i : it) {
                if (i == 1) {
                    done = false;
                    break;
                }
            }
        }
        if (done)
            return 0;
        if (node == m * n)
            return 100;
        int ans = 0;
        ans = f(node + 1, mat);
        int r = node / n;
        int c = node % n;
        mat[r][c] = !(mat[r][c]);
        if (r - 1 >= 0)
            mat[r - 1][c] = !mat[r - 1][c];
        if (r + 1 < m)
            mat[r + 1][c] = !mat[r + 1][c];
        if (c - 1 >= 0)
            mat[r][c - 1] = !mat[r][c - 1];
        if (c + 1 < n)
            mat[r][c + 1] = !mat[r][c + 1];
        ans = min(ans, 1 + f(node + 1, mat));
        return ans;
    }
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        int ans = f(0, mat);
        if (ans == 100)
            return -1;
        return ans;
    }
};