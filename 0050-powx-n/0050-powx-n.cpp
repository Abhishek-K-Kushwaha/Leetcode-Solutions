#include <vector>
using namespace std;

class Solution {
private:
    vector<double> dp = vector<double>(32, 0);
    
    double f(double x, long long n) {
        if (n == 0) return 1;
        if (x == 0 || n == 1) return x;
        long long m = 1;
        int i = 0;
        double ans = x;
        while (m * 2 <= n) {
            m *= 2;
            i++;
            if (dp[i] != 0) ans = dp[i];
            else {
                ans *= ans;
                dp[i] = ans;
            }
        }
        return ans * myPow(x, n - m);
    }

public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0) return 0;
        if (n == INT_MIN) {
            return 1 / (f(x, (long long)INT_MAX) * x); // Special case for INT_MIN
        }
        if (n >= 0) return f(x, n);
        else return 1 / f(x, (long long)-n);
    }
};
