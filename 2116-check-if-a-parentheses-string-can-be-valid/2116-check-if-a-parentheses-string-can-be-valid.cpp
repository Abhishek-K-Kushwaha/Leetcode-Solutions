class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> open;
        stack<int> both;
        int n = s.size();
        if (n % 2)
            return false;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
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