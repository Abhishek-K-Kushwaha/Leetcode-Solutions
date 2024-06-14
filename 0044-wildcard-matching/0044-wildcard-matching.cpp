#include <cstring>
class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (j < 0 && i < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (j >= 0 && i < 0) {
            for (int it = 0; it <= j; it++) {
                if (p[it] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[j] == '*') {
            bool notmatch = f(i, j - 1, s, p, dp);
            bool match = f(i - 1, j, s, p, dp);
            return dp[i][j] = (notmatch || match);
        }
        if (p[j] == '?' || s[i] == p[j])
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, p, dp);
    }
};