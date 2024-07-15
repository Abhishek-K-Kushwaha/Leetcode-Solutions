class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> freq;
        for(auto i: nums){
            freq[-i]++;
        }
        for (auto& it: freq){
            if (k <= it.second) return -it.first;
            k -= it.second;
        }
        return -1;
    }
};