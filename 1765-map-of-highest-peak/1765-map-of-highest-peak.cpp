class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, INT_MAX));
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j]){ 
                    q.push({0, i*n + j});
                    ans[i][j] = 0;
                }
            }
        }
        int d, ind, r, c, nr, nc;
        vector<int> dr = {0,0,1,-1};
        vector<int> dc = {1,-1,0,0};
        while (!q.empty()){
            d = q.front().first;
            ind = q.front().second;
            q.pop();
            r = ind / n;
            c = ind % n;
            for (int i = 0; i < 4; i++){
                nr = r + dr[i];
                nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && ans[nr][nc] > d+1){
                    ans[nr][nc] = d+1;
                    // cout<< nr << " "<< nc << ", ";
                    q.push({d+1, nr*n + nc});
                }
            }
            // cout << endl;
        }
        return ans;
    }
};