class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) return 0;
        vector<int> nums(11,0);
        int i = 0, m = n;
        while(n){
            nums[i] = n % 10;
            n /= 10;
            i++;
        }
        int ans = (m-1)/10 + 1;
        //cout << ans<< endl;
        for (int i = 1; i < 10; i++){
            long long div = pow(10, i+1);
            ans +=  m/div * pow(10,i);
            if (nums[i] >= 2){
                ans +=  pow(10, i);
            }
            else if (nums[i] == 1){
                ans += (m)%(int)pow(10,i) +1;
            }
        }
        return ans;
    }
};