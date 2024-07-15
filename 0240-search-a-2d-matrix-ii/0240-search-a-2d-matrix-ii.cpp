class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, right = n-1;
        while (up < m && right >= 0){
            if (target > matrix[up][right]) up++;
            else if (target < matrix[up][right]) right--;
            else return true;
        }
        return false;;
    }
};