class Solution {
public:
    void f(string s, int i, int n, vector<string>& ans) {
        if (i == n) {
            ans.push_back(s);
            return;
        }
        f(s + "1", i + 1, n, ans);
        if (i == 0 || s[i - 1] == '1') {
            f(s + "0", i + 1, n, ans);
        }
    }
    
    vector<string> validStrings(int n) {
        vector<string> ans;
        f("", 0, n, ans);
        return ans;
    }
};