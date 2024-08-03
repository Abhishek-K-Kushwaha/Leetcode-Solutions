class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        unordered_map<int,int> freq;
        for (int i=0;i<n;i++){
            freq[arr[i]]++;
            freq[target[i]]--;
        }
        for (auto& it:freq){
            if (it.second) return false;
        }
        return true;
    }
};