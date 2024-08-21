class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1, -1);
        deque<int> dq;
        for (int i = 0; i < k; i++){
            //if (dq.empty()) dq.push_back(nums[i]);
            while (!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        for (int i = k; i < n; i++){
            ans[i-k] = dq.front();
            if (nums[i-k] == dq.front()) dq.pop_front();
            while (!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans[n-k] = dq.front();
        return ans;        
    }
};