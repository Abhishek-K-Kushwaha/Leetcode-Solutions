class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> triangle = {1};
        long long num = 1;
        for (int j = 1; j <= n; j++) {
            num = num * (n - j + 1) / j;
            triangle.push_back(num);
        }
        return triangle;
    }
};