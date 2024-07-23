class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; i++) {
            string ans = "";
            int len = str.size();
            int cnt = 1;
            for (int i = 1; i < len; i++) {
                if (str[i] != str[i - 1]) {
                    ans.push_back(char(cnt + 48));
                    ans.push_back(str[i - 1]);
                    cnt = 1;
                } else
                    cnt++;
            }
            ans.push_back(char(cnt + 48));
            ans.push_back(str[len - 1]);
            str = ans;
        }
        return str;
    }
};