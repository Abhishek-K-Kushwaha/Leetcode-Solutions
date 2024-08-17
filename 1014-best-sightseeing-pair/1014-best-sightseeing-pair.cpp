class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxscore = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, values[i] + maxscore);
            maxscore = max(values[i], maxscore)-1;
        }
        return ans;
    }
};