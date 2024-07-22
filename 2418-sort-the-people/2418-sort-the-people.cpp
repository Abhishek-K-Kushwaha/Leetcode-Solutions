class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        map<int,string> dict;
        int n = names.size();
        for (int i = 0; i < n; i++){
            dict[-heights[i]] = names[i];
        }
        for (auto& it:dict){
            ans.push_back(it.second);
        }
        return ans;
    }
};