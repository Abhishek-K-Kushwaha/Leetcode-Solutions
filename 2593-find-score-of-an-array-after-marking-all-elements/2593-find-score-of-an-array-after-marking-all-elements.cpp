class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        set<pair<int,int>> st;
        for (int i = 0; i< n; i++){
            st.insert({nums[i], i});
        }
        vector<bool> marked(n, false);
        int cnt = 0;
        long long ans = 0;
        while (cnt < n){
            auto [x,y] = *st.begin();
            ans += x;
            //cout << ans << endl;
            st.erase({x,y});
            marked[y] = 1;
            cnt++;
            if (y > 0 && !marked[y-1]){
                st.erase({nums[y-1], y-1});
                cnt++;
                marked[y-1] = 1;
            }
            if (y < n-1 && !marked[y+1]){
                st.erase({nums[y+1], y+1});
                cnt++;
                marked[y+1] = 1;
            }

        }
        return ans;

    }
};