class Solution {
public:
    int f(int h, vector<pair<int,int>>& stk){
        int l = 0;
        int r = stk.size()- 1;
        int ans = -1;
        while (l <= r){
            int mid = (l+r)/2;
            if (stk[mid].first > h){
                ans = max(ans, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<vector<pair<int,int>>> q(n);
        vector<int> ans(queries.size(), -1);
        int i = 0;
        for (auto& it:queries){
            if (it[0] > it[1]){
                swap(it[0], it[1]);
            }
            if (it[0] == it[1] || heights[it[0]] < heights[it[1]]){
                ans[i] = it[1];
            }
            else{
                q[it[1]].push_back({heights[it[0]], i});
            }
            i++;
        }
        
        vector<pair<int,int>> stk; //height, index
        // int ind = heights.size() - 1;
        for (int i = n-1; i >= 0; i--){
            for (auto& it:q[i]){
                int h = it.first;
                int ind = it.second;
                int pos = f(h, stk);
                if (pos >= 0) ans[ind] = stk[pos].second;
            }
            while (!stk.empty() && stk.back().first < heights[i]) stk.pop_back();
            stk.push_back({heights[i], i});
        }
        return ans;
    }
};