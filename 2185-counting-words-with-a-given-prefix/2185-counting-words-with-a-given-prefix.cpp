class Solution {
public:
    bool f(string& st, string& s){
        int i = 0;
        while (i < s.size() && st[i]==s[i]) i++;
        return (i==s.size());
    }
    int prefixCount(vector<string>& words, string pref) {
        int len = pref.size();
        int ans = 0;
        for(auto& w:words){
            if (w.size() >= len && f(w,pref)) ans++;
        }
        return ans;
    }
};