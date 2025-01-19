class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        vector<int> r(n);
        // l[1] = height[0];
        // for (int i = 2; i < n-1; i++){
        //     l[i] = max(l[i-1], height[i-1]);
        // }
        r[n-2] = height[n-1];
        for (int i = n-3; i > 0; i--){
            r[i] = max(r[i+1], height[i+1]);
        }
        int ans = 0, lvl, li = height[0];
        for (int i = 1; i < n-1; i++){
            lvl = min(li, r[i]); 
            if (lvl > height[i]) ans += (lvl - height[i]); 
            li = max(li, height[i]);
        }
        return ans;
    }
};