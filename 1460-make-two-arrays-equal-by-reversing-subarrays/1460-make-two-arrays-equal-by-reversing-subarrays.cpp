class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int ans = 0;
        unordered_map<int,int> freq;
        for (int i: target){
            freq[i]++;
        }
        for (int i:arr){
            freq[i]--;
        }
        for (auto& it:freq){
            if (it.second) return false;
        }
        return true;
    }
};