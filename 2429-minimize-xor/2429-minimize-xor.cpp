class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> ans(0);
        bitset<32> n(num1);
        bitset<32> m(num2);
        int cnt = m.count();
        int i = 31;
        while (cnt && i >= 0){
            if (n[i] == 1){
                ans[i] = 1;
                cnt--;
            } 
            i--;
        }
        i = 0;
        while (cnt && i < 32){
            if (n[i] == 0){
                ans[i] = 1;
                cnt--;
            }
            i++;
        }
        return ans.to_ulong();
    }
};