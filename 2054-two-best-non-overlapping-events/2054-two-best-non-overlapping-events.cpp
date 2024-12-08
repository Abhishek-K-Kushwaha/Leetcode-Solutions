class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> postmax(n);
        int m = 0;
        for (int i = n - 1; i >= 0; i--) {
            postmax[i] = max(m, events[i][2]);
            m = postmax[i];
        }
        int ans = m, val, end, ind;
        for (int i = 0; i < n; i++) {
            val = events[i][2];
            end = events[i][1];
            vector<int> temp(3, 0);
            temp[0] = end + 1;
            auto it = lower_bound(events.begin(), events.end(), temp);
            ind = (it - events.begin());
            if (ind < n)
                val += postmax[ind];
            ans = max(ans, val);
        }
        return ans;
    }
};