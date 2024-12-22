class Solution {
public:
    vector<vector<string>> ans;
    void put(int r, int n, vector<bool>& c, vector<bool>& d,
             vector<bool>& invd, vector<string>& temp) {
        if (r == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!c[i] && !d[r + i] && !invd[r - i + n-1]) {
                c[i] = 1, d[r + i] = 1, invd[r - i + n-1] = 1;
                temp[r][i] = 'Q';
                put(r + 1, n, c, d, invd, temp);
                c[i] = 0, d[r + i] = 0, invd[r - i + n-1] = 0;
                temp[r][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<bool> c(n, 0);
        vector<bool> d(2*n-1, 0);    // i = sum /-shaped
        vector<bool> invd(2*n-1, 0); // i = diff+8 \-shaped
        string b(n,'.');
        vector<string> temp(n, b);
        put(0, n, c, d, invd, temp);
        return ans;
    }
};