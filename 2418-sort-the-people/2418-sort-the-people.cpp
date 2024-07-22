class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> dict;
        int n = names.size();
        for (int i = 0; i < n; i++){
            dict[-heights[i]] = names[i];
        }
        int i = 0;
        for (auto& it:dict){
            names[i] = (it.second);
            i++;
        }
        return names;
    }
};