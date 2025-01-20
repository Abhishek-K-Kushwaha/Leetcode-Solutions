class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int> stk;
        stk.push(0);
        int ans = 0;
        for (int i : target) {
            if (i > stk.top()) {
                ans += (i - stk.top());
                stk.push(i);
            } else {
                while (stk.top() >= i) {
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return ans;
    }
};