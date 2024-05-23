class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows,{1});
        for (int i = 1; i < numRows; i++){
            int num = 1;
            for (int j = 1; j <= i; j++){
                num = num*(i-j+1)/j;
                triangle[i].push_back(num);
            }
        }
        return triangle;
    }
};