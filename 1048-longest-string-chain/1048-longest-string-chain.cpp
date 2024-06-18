class Solution {
public:
    bool compare(string& word1, string& word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 != len2 + 1)
            return false;
        int i = 0;
        int j = 0;
        while (i < len1) {
            if (word1[i] == word2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if (i == len1 && j == len2)
            return true;
        return false;
    }

    static bool comp(string& s1, string& s2) { return s1.size() < s2.size(); }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        // vector<int>
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (compare(words[i], words[j]) && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};