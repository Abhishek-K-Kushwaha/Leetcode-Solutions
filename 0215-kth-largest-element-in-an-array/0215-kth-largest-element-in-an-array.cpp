class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> freq;
        for(auto i: nums){
            freq[-i]++;
        }
        // set<pair<int,int>> st;
        // for (auto& it:freq){
        //     st.insert(it);
        //     if (st.size() > k){
        //         st.erase(prev(st.end()));
        //     }
        // }
        for (auto& it: freq){
            if (k <= it.second) return -it.first;
            k -= it.second;
        }
        return -1;
    }
};