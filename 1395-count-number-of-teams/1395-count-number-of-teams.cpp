class Solution {
public:
    int f(int i, int cnt, int last, vector<int>& rating, vector<vector<vector<int>>>& dp) {
        if (cnt == 3)
        return dp[i][last+1][cnt] = 1;
        if (i == rating.size())
            return 0;
        if (dp[i][last+1][cnt] != -1) return dp[i][last+1][cnt];
        int pick = 0;
        if (last < 0 || rating[i] > rating[last])
            pick = f(i + 1, cnt + 1, i, rating, dp);
        int notpick = f(i + 1, cnt, last, rating, dp);
        return dp[i][last+1][cnt] = pick + notpick;
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(4, -1)));
        int cnt1 = f(0, 0, -1, rating, dp);
        //vector<vector<vector<int>>> dprev(n+1, vector<vector<int>>(n+1, vector<int>(4, -1)));
        vector<vector<int>> temp(n+1, vector<int>(4, -1));
        fill(dp.begin(), dp.end(), temp);
        reverse(rating.begin(), rating.end());
        int cnt2 = f(0, 0, -1, rating, dp);

        return cnt1 + cnt2;
    }
};