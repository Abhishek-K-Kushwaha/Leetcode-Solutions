class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) return false;
        stack<char> stk;
        for (auto c:s){
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            else{
                if (stk.empty()) return false;
                    else{
                    int diff = c - stk.top();
                    if (diff == 1 || diff == 2) stk.pop();
                    else return false;
                }
            }
        }
        if (stk.empty())return true;
        else return false;
    }
};