class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int r = 0; r < m; r++){
            for (int c= 1; c<n; c++){
                matrix[r][c] += matrix[r][c-1];
            }
        }
        int ans = 0;
        int sum;
        unordered_map<int,int> dict;
        for (int l = 0; l < n; l++){
            for (int r = l; r < n; r++){
                dict = {{0,1}};
                sum = 0;
                for (int i= 0; i < m; i++){
                    sum += matrix[i][r];
                    if (l > 0) sum -= matrix[i][l-1];
                    if (dict.find(sum-target) != dict.end()) ans += dict[sum-target];
                    dict[sum]++;
                }
            }
        }
        return ans;
    }
};