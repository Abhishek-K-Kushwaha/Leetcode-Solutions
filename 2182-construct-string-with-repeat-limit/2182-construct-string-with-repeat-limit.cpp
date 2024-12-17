class Solution {
public:
    string repeatLimitedString(string s, int lim) {
        vector<int> freq(26, 0);
        for (auto it : s) {
            freq[it - 'a']++;
        }
        int r = 25, l = r - 1, cnt = 0;
        string ans;
        while (r >= 0) {
            while (r >= 0 && !freq[r]) {
                r--;
            }
            if (r < 0)
                break;
            cnt = 0;
            while (freq[r] > 0 && cnt < lim) {
                ans.push_back('a' + r);
                cnt++;
                freq[r]--;
            }
            if (freq[r] == 0) {
                r--;
                continue;
            }
            l = r - 1;
            while (l >= 0 && !freq[l]) {
                l--;
            }
            if (l >= 0) {
                ans.push_back('a' + l);
                freq[l]--;
            } else
                break;
        }
        return ans;
    }
};