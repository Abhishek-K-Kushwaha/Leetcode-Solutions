class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m-1, left = 0, right = n-1;
        //if (target < matrix[up][left] || target > matrix[down][right]) return false;
        while (up <= down && left <= right){
            if (target > matrix[up][right]) up++;
            else if (target < matrix[up][right]) right--;
            else return true;
            if (target > matrix[down][left]) left++;
            else if (target < matrix[down][left]) down--;
            else return true;
        }
        return false;;
    }
};