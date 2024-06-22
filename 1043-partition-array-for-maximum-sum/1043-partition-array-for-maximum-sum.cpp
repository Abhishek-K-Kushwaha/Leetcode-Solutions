class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n-1; i >= 0; i-- ){
            int ans = 0;
            int maxval = 0;
            for (int j = 1; j <= k; j++){
                if (i + j <= n){
                    maxval = max(maxval, arr[i+j-1]);
                    int val = j*maxval + dp[i+j]; 
                    ans = max(ans, val);
                }
            }
            dp[i] = ans;
        }
        return dp[0]; 
    }
};