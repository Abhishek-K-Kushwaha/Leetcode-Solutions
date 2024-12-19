class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxi;
        stack<int> stk;
        for (int i = 0; i < n; i++){
            if (stk.empty() || arr[i] >= stk.top()){
                stk.push(arr[i]);
            } else{
                maxi = stk.top();
                while (!stk.empty() && stk.top() > arr[i]){
                    stk.pop();
                }
                stk.push(maxi);
            }
        }
        return stk.size();
    }
};