class Solution {
public:
    bool isPalindrome(string& s,int i, int j){
        while (i < j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i = n-1; i >= 0; i--){
            int ans = n;
            for (int j = i; j < n; j++){
                if (isPalindrome(s,i,j)){
                    int cuts = 1 + dp[j+1]; // f(j+1, s, n, dp);
                    ans = min(ans, cuts);
                }
            }
            dp[i] = ans;
        }
        return dp[0] - 1;
    }
};