class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> winsum(n+1-k);
        winsum[0] = accumulate(nums.begin(), nums.begin()+k,0);
        for (int i = k; i < n; i++){
            winsum[i-k+1] = winsum[i-k]+nums[i]-nums[i-k];
        }
        vector<int> lmax(n);
        int maxsum = 0;
        for (int i = k-1; i <= n-k; i++){
            if (winsum[i-k+1] > maxsum){
                lmax[i] = i - k + 1;
                maxsum = winsum[i-k+1];
            }
            else{
                lmax[i] = lmax[i-1];
            }
        }
        // for (auto it: lmax){
        //     cout << it << endl;
        // }
        vector<int> rmax(n);
        maxsum = 0;
        for (int i = n-k; i >= k; i--){
            if (winsum[i] >= maxsum){
                rmax[i] = i;
                maxsum = winsum[i];
            }
            else{
                rmax[i] = rmax[i+1];
            }
        }
        int l, r;
        vector<int> ans(3);
        maxsum = 0;
        for (int i = k; i <= n-2*k; i++){
            l = lmax[i-1];
            r = rmax[i+k];
            if (winsum[l]+winsum[r]+winsum[i] > maxsum){
                ans = {l,i,r};
                //ans[0] = l, ans[1] = i, ans[2] = r;
                maxsum = winsum[l]+winsum[r]+winsum[i];
            }
        }
        return ans;
    }
};