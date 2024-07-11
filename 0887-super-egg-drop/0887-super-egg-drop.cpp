class Solution {
public:
    int superEggDrop(int n, int k) {
        vector<int> prev(k+1);
        for (int i = 0; i <= k; i++){
            prev[i] = i;
        }
        vector<int> curr(k+1);
        for (int i = 2; i <= n; i++){
            curr[1] = 1; 
            for (int j = 2; j <= k; j++){
                int ans = INT_MAX;
                for (int x = 1; x <= j; x++){
                    int brk = 1 + prev[x-1]; //f(n-1, i-1, dp);
                    int notbrk = 1 + curr[j-x]; //f(n, k-i, dp);
                    ans = min(ans, max(brk,notbrk));
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[k];//f(n,k, dp);
    }
};