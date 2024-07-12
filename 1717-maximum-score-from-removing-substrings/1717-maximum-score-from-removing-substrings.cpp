class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> stk;
        char first, second;
        if (x > y){
            first = 'a';
            second = 'b';
        }
        else{
            first = 'b';
            second = 'a';
            swap(x,y);
        }
        int ans = 0;
        for (auto c:s){
            if (!stk.empty() && stk.top() == first && c == second){
                ans += x;
                stk.pop();
            }
            else{
                stk.push(c);
            }
        }
        stack<char> st;
        while(!stk.empty()){
            char c = stk.top();
            if (!st.empty() && st.top() == first && c == second){
                ans += y;
                st.pop();
            }
            else st.push(c);
            stk.pop();
        }
        return ans;

    }
};