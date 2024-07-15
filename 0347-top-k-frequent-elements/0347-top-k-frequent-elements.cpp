class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        set<pair<int,int>> st;
        for (int i:nums){
            freq[i]--;
        }
        for (auto it:freq){
            st.insert({it.second, it.first});
            if (st.size() > k) st.erase(prev(st.end()));
        }
        vector<int> ans;
        int i = 0;
        for (auto it:st){
            ans.push_back(it.second);
            i++;
            //if (i == k) return ans;
        }
        return ans;
    }
};