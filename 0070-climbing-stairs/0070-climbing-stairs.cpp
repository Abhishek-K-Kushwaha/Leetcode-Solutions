class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev = 1;
        int ans = 2;
        for (int i = 2; i < n; i++){
            int nxt = prev + ans;
            prev = ans;
            ans = nxt;
        }
        return ans;
    }
};