class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> loc(m*n+1);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                loc[mat[i][j]] = i*n + j;
            }
        }
        vector<int> rcnt(m, 0), ccnt(n, 0);
        for (int i = 0; i < arr.size(); i++){
            auto it = loc[arr[i]];
            rcnt[it / n]++; ccnt[it % n]++;
            if (rcnt[it / n] == n || ccnt[it % n] == m) return i; 
        }
        return -1;
    }
};