class Solution {
public:
    string convertToTitle(int N) {
        string str;
        int rem;
        while (N != 0) {
            rem = (N - 1) % 26;
            str += (rem + 'A');
            N = (N - 1) / 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};