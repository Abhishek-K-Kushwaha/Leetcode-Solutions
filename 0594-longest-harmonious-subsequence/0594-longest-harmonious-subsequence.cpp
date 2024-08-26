class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int i:nums){
            freq[i]++;
        }
        int ans = 0;
        for (auto it:freq){
            int num = it.first;
            
            if (freq.find(num-1) != freq.end()) ans = max(ans, freq[num]+freq[num-1]);
            if (freq.find(num+1) != freq.end()) ans = max(ans, freq[num]+freq[num+1]);
            //cout << num << " " << ans << endl;
        }
        return ans;
    }
};