class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else {
            int revx = 0;
            int orgx = x;

            while (x != 0) {
                int pop = x % 10;
                x /= 10;
                if (revx > INT_MAX / 10 || (revx == INT_MAX / 10 && pop > 7))
                    return false;
                if (revx < INT_MIN / 10 || (revx == INT_MIN / 10 && pop < -8))
                    return false;
                revx = revx * 10 + pop;
            }
            return (revx == orgx);
        }
    }
};