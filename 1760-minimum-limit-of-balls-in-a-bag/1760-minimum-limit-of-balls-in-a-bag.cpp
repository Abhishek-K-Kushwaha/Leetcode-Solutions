class Solution {
private:
    bool f(int m, vector<int>& nums, int maxop){
        int cnt = 0;
        for (int i:nums){
            if (i%m) cnt = cnt+(i/m)+1;
            else cnt += (i/m);
            if (cnt > maxop) return false;
        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while (l < r){
            int m = (l+r)/2;
            if (f(m, nums, n+maxOperations)) r = m;
            else l = m + 1;
        }
        return l;
    }
};