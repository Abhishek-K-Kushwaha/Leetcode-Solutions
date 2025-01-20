class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size();
        int numCols = mat[0].size();
        vector<int> numToIndex(numRows * numCols + 1);
        for (int i = 0; i < arr.size(); i++) {
            numToIndex[arr[i]] = i;
        }
        int result = INT_MAX;
        for (int row = 0; row < numRows; row++) {
            int lastElementIndex = INT_MIN;
            for (int col = 0; col < numCols; col++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            result = min(result, lastElementIndex);
        }
        for (int col = 0; col < numCols; col++) {
            int lastElementIndex = INT_MIN;
            for (int row = 0; row < numRows; row++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            result = min(result, lastElementIndex);
        }
        return result;
    }
};