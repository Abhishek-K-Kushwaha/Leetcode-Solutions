class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(4, 0)));
        for (int i = 0; i <= n; i++){
            for (int last = 0; last <= n; last++){
                dp[i][last][3] = 1;
            }
        }
        for (int i = n-1; i >= 0; i--){
            for (int last = i-1; last >= -1; last--){
                for (int cnt = 2; cnt >= 0; cnt--){
                    int pick = 0;
                    if (last < 0 || rating[i] > rating[last])
                        pick = dp[i+1][i+1][cnt+1]; //f(i + 1, cnt + 1, i, rating, dp);
                    int notpick = dp[i+1][last+1][cnt]; //f(i + 1, cnt, last, rating, dp);
                    dp[i][last+1][cnt] = pick + notpick;
                }
            }
        }
        int cnt1 = dp[0][0][0]; //f(0, 0, -1, rating, dp);
        //cout << cnt1 << " ";
        vector<vector<int>> temp(n+1, vector<int>(4, 0));
        fill(dp.begin(), dp.end(), temp);
        reverse(rating.begin(), rating.end());

        for (int i = 0; i <= n; i++){
            for (int last = 0; last <= n; last++){
                dp[i][last][3] = 1;
            }
        }
        for (int i = n-1; i >= 0; i--){
            for (int last = i-1; last >= -1; last--){
                for (int cnt = 2; cnt >= 0; cnt--){
                    int pick = 0;
                    if (last < 0 || rating[i] > rating[last])
                        pick = dp[i+1][i+1][cnt+1]; //f(i + 1, cnt + 1, i, rating, dp);
                    int notpick = dp[i+1][last+1][cnt]; //f(i + 1, cnt, last, rating, dp);
                    dp[i][last+1][cnt] = pick + notpick;
                }
            }
        }
        int cnt2 = dp[0][0][0]; //f(0, 0, -1, rating, dp);
        //cout << cnt2;
        return cnt1 + cnt2;
    }
};