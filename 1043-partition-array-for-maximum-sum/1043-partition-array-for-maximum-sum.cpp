class Solution {
public:
    int f(int i, int k, vector<int>& arr, int n, vector<int>& dp){
        if (i == n) return 0;
        //if (i == n-1) return dp[i] = arr[n-1];
        if (dp[i] != -1) return dp[i];
        int ans = 0;
        for (int j = 1; j <= k; j++){
            if (i + j <= n){auto it = max_element(arr.begin() + i, arr.begin() + i + j);
            int itval = *it;
            int val = j*itval + f(i+j, k, arr, n, dp);
            ans = max(ans, val);}
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, k, arr, n, dp);
    }
};