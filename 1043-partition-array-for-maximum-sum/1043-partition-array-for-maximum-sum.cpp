class Solution {
public:
    int maxele(int i, int j, vector<int>& arr, vector<vector<int>>& maxdp){
        if (i > j) return 0;
        if (i == j) return arr[i];
        if (maxdp[i][j] != -1) return maxdp[i][j];
        return maxdp[i][j] = max({arr[i], arr[j], maxele(i+1, j-1, arr, maxdp)});
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> maxdp(n, vector<int> (n, -1));
        vector<int> dp(n + 1, 0);
        for (int i = n-1; i >= 0; i-- ){
            int ans = 0;
            for (int j = 1; j <= k; j++){
                if (i + j <= n){
                    //auto it = max_element(arr.begin() + i, arr.begin() + i + j);
                    //int itval = *it;
                    int itval = maxele(i, i+j-1, arr, maxdp);
                    int val = j*itval + dp[i+j]; //f(i+j, k, arr, n, dp);
                    ans = max(ans, val);
                }
            }
            dp[i] = ans;
        }
        return dp[0]; // f(0, k, arr, n, dp);
    }
};