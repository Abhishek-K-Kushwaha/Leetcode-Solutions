class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<pair<int, int>> stk;
        int mini, maxi;
        for (int i:arr){
            if (stk.empty() || stk.top().second < i){
                stk.push({i,i});
            }
            else if (stk.top().first > i){
                maxi = stk.top().second;
                mini = i;
                stk.pop();
                while (!stk.empty() && stk.top().second > i){
                    mini = min(mini, stk.top().first);
                    stk.pop();
                }
                stk.push({mini, maxi});
            }
            // while (!stk.empty() && stk.top(). > i){
            //     stk.pop();
            // }
            // stk.push(i);
        }
        return stk.size();
    }
};