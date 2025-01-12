class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, both;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i]=='*') {
                both.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else if (!open.empty()) {
                    open.pop();
            } else if (!both.empty()) {
                both.pop();
            } else
                return false;
        }
        while (!both.empty() && !open.empty() && open.top() < both.top()) {
            both.pop();
            open.pop();
        }
        if (!open.empty())
            return false;
        return true;
    }
};