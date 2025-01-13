class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (auto& c : s) {
            freq[c - 'a']++;
        }
        int ans = 0;
        for (int i : freq) {
            if (i % 2)
                ans += 1;
            else if (i)
                ans += 2;
        }
        return ans;
    }
};