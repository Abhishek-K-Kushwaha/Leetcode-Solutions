class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> freq;
        int n = nums.size();
        for (int i = 0; i < k; i++){
            freq[nums[i]]++;
        }
        vector<int> ans(n-k+1);
        auto it = prev(freq.end());
        ans[0] = it->first;
        int ind = 1;
        for (int i = k; i < n; i++){
            int to_remove = nums[i-k];
            freq[to_remove]--;
            if (freq[to_remove] == 0) freq.erase(to_remove);
            freq[nums[i]]++;
            it = prev(freq.end());
            ans[ind] = it->first;
            ind++;
        }
        return ans;
    }
};