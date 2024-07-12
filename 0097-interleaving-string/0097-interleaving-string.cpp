class Solution {
public:
    bool f(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        int k = i + j;
        if (k == s3.size()) return true;
        if (i < s1.size() && j < s2.size() && dp[i][j] != -1) return dp[i][j];
        bool first = false;
        bool second = false;
        if (i < s1.size() && s1[i] == s3[k]){
            first = f(i+1, j, s1, s2, s3, dp);
        }
        if (j < s2.size() && s2[j] == s3[k]){
            second = f(i, j+1, s1, s2, s3, dp);
        }
        return dp[i][j] = (first || second);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int l = s3.size();
        if (m+n != l) return false;
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        //for (int i = )

        return f(0,0,s1,s2,s3, dp);
    }
};