class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        map<int, int> dict; // position --> index of robot
        int n = positions.size();
        for (int i = 0; i < n; i++) {
            dict[positions[i]] = i;
        }
        stack<int> stk; // index
        for (auto it : dict) {
            int ind = it.second;
            if (directions[ind] == 'R') {
                stk.push(ind);
            } 
            else {
                while (!stk.empty() && healths[ind] > 0) {
                    // healths[ind]--;
                    // stk.pop();
                    if (healths[stk.top()] == healths[ind]){
                        healths[stk.top()] = 0;
                        stk.pop();
                        healths[ind] = 0;
                    }
                    else if (healths[stk.top()] > healths[ind]){
                        healths[stk.top()]--;
                        healths[ind] = 0;
                    }
                    else{
                        healths[stk.top()] = 0;
                        stk.pop();
                        healths[ind]--;
                    }
                }
            }
        }
        // int len = stk.size();
        // set<int> ans;
        // // int i = len-1;
        // while (!stk.empty()) {
        //     ans.insert(stk.top());
        //     stk.pop();
        //     // i--;
        // }
        vector<int> result;
        for (int i : healths) {
            if (i) result.push_back(i);
        }
        return result;
    }
};