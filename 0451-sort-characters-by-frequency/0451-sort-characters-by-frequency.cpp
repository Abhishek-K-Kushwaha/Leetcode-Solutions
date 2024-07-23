class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(75);
        for (auto i : s) {
            freq[i - '0']++;
        }
        // cout << freq['a'-'A'] << " " << freq['k'-'A'];
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (freq[a - '0'] != freq[b - '0'])
                return freq[a - '0'] > freq[b - '0'];
            return a < b;
        });
        return s;
    }
};