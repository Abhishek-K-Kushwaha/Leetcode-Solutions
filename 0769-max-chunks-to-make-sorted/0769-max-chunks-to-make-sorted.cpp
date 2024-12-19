class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        int mini, maxi;
        for (int i : arr) {
            if (stk.empty() || stk.top() < i) {
                stk.push(i);
            } else if (stk.top() > i) {
                maxi = stk.top();
                //mini = i;
                stk.pop();
                while (!stk.empty() && stk.top() > i) {
                    //maxi = min(mini, stk.top().first);
                    stk.pop();
                }
                stk.push(maxi);
            }
        }
        return stk.size();
    }
};