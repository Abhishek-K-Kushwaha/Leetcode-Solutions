class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prev(n), curr(n);
        for (int i = 0; i < n; i++){
            prev[i] = points[0][i];
        }
        for (int r = 1; r < m; r++){
            long long maxscore = 0;
            for (int c = 0; c < n; c++){
                curr[c] = points[r][c] + max(maxscore, prev[c]);
                maxscore = max(maxscore, prev[c]) - 1;
                //cout << maxscore << " ";
            }
            //cout << endl;
            maxscore = 0;
            for (int c = n-1; c >= 0; c--){
                curr[c] = max(curr[c], points[r][c] + maxscore);
                maxscore =  max(maxscore, prev[c]) - 1;
                //cout << maxscore << " ";
            }
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};