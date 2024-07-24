class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> vals; // orgnum -> {ind, val}
        for (int num:nums){
            int org = num;
            int val = 0;
            int i = 1;
            if (org == 0){
                vals[org] = mapping[0];
                continue;
            }
            while(num){
                int r = num % 10;
                num /= 10;
                val += mapping[r] * i;
                i *= 10;
            }
            vals[org] = val;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return vals[a] < vals[b];
        });
        // for (auto it: vals){
        //     cout << it << " ";
        // }
        return nums;
    }
};