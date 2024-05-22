class Solution {
public:
    int titleToNumber(string str) {
        int val = 0;
        for (int i = 0; i < str.size(); i++){
            val = val * 26 + (str[i] - 64);
        }
        return val;
    }
};