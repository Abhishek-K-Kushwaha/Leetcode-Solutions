class Solution {
public:
    int fib(int n) {
        vector<int> lst;
        lst.push_back(0);
        lst.push_back(1);
        int num = 1;
        for (int i = 2; i <= 30; i++) {
            num = lst[i - 2] + num;
            lst.push_back(num);
        }
        return lst[n];
    }
};