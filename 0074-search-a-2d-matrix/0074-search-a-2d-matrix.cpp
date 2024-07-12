class Solution {
public:
    bool search(vector<int>& row, int target){
        int n = row.size();
        int i = 0;
        int j = n-1;
        while (i <= j){
            int mid = i + (j - i)/2;
            if (row[mid] == target) return true;
            if (row[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int i = 0;
        int j = n-1;
        int mid;
        while (i <= j){
            mid = i + (j - i)/2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] > target) j = mid - 1;
            else i = mid + 1;
        }
        if (i) i--;
        return search(matrix[i], target);
    }
};