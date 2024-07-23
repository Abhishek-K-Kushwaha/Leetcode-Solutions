class Solution {
public:
    int N;
    string f(int i, string& str){
        if (i == N) return str;
        string ans = "";
        int n = str.size();
        int cnt = 1;
        char prev = str[0];
        for (int i = 1; i < n; i++){
            if (str[i] != str[i-1]){
                ans.push_back(char(cnt+48));
                ans.push_back(str[i-1]);
                cnt = 1;
            }
            else cnt++;
        }
        ans.push_back(char(cnt+48));
        ans.push_back(str[n-1]);
        return f(i+1, ans);
    }
    string countAndSay(int n) {
        N = n;
        string base = "1";
        return f(1, base);
    }
};