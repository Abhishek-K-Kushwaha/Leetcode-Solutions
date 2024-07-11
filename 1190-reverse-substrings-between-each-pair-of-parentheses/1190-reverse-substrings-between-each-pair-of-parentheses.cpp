class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<int> stk;
        int i = 0;
        for (auto& c:s){
            if (c == '('){
                stk.push(i);
            }
            else if (c == ')'){
                int end = i;
                int start = stk.top();
                stk.pop();
                reverse(ans.begin()+start, ans.begin()+end);
            }
            else{
                ans.push_back(c);
                i++;
            }
        }
        return ans;
    }
};