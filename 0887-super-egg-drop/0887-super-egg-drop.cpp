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
                curr[j] = INT_MAX;
                int low = 1, high = j;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    int brk = 1 + prev[mid - 1];
                    int notbrk = 1 + curr[j - mid];
                    int worst = max(brk, notbrk);
                    curr[j] = min(curr[j], worst);
                    if (brk > notbrk) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            prev = curr;
        }
        return prev[k];//f(n,k, dp);
    }
};