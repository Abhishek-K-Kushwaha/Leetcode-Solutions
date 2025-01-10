class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1 = words1.size(), n2 = words2.size();
        vector<string> ans;
        vector<int> maxfreq(26, 0);
        vector<int> curr(26);
        for (auto& w2 : words2) {
            fill(curr.begin(), curr.end(),0);
            for (auto c : w2) {
                curr[c - 'a']++;
                maxfreq[c - 'a'] = max(curr[c - 'a'], maxfreq[c - 'a']);
            }
        }
        for (auto& w1 : words1) {
            vector<int> freq(26, 0);
            for (auto c : w1) {
                freq[c - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (maxfreq[i] > freq[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.emplace_back(w1);
        }
        return ans;
    }
};