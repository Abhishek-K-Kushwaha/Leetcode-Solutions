class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        //vector<int> vals;
        //vector<int> numscopy = nums;
        //cout << nums.size() << " ";
        unordered_map<int, pair<int,int>> vals; // orgnum -> {ind, val}
        int ind = 0;
        for (int num:nums){
            int org = num;
            int val = 0;
            int i = 0;
            if (org == 0){
                vals[org] = {ind,(mapping[0])};
                ind++;
                continue;
            }
            while(num){
                int r = num % 10;
                num /= 10;
                val += mapping[r] * pow(10,i);
                i++;
            }
            vals[org] = {ind, val};
            ind++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            int inda = vals[a].first; //find(nums.begin(), nums.end(), a) - nums.begin();
            int indb = vals[b].first; //find(nums.begin(), nums.end(), b) - nums.begin();
            if (vals[a].second == vals[b].second) return inda < indb;
            return vals[a].second < vals[b].second;
        });
        // for (auto it: vals){
        //     cout << it << " ";
        // }
        return nums;
    }
};