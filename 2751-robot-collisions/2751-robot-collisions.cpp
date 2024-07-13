class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int,int> dict; //position --> index of robot
        int n = positions.size();
        for (int i = 0; i < n; i++){
            dict[positions[i]] = i;
        }
        stack<int> stk; // index
        for (auto it:dict){
            //int pos = it.first;
            //cout<< it.second << " ";
            int ind = it.second;
            if (stk.empty() || directions[stk.top()] == 'L' || directions[ind] == 'R'){
                // if (directions[ind] == 'L') stk.push({health[ind], -1});
                // else stk.push({health[ind], 1});
                stk.push(ind);
            }
            else{
                if (healths[ind] == healths[stk.top()]){
                    stk.pop();
                }
                else if (healths[ind] < healths[stk.top()]){
                    healths[stk.top()]--;
                }
                else{
                    while(!stk.empty() && healths[stk.top()] < healths[ind] && directions[stk.top()] == 'R'){
                        healths[ind]--;
                        stk.pop();
                    }
                    if (stk.empty()) stk.push(ind);
                    else if (healths[stk.top()] == healths[ind] && directions[stk.top()] == 'R') stk.pop();
                    else if (directions[stk.top()] == 'R') healths[stk.top()]--;
                    else stk.push(ind);
                }
            }
        }
        //int len = stk.size();
        set<int> ans;
        //int i = len-1;
        while(!stk.empty()){
            ans.insert(stk.top());
            stk.pop();
            //i--;
        }
        vector<int> result;
        for (int i:ans){
            result.push_back(healths[i]);
        }
        return result;
    }
};