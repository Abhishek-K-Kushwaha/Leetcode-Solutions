class Solution {
public:
    string frequencySort(string s) {
        // Create a frequency map
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Sort the string based on the frequency map
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            }
            return a < b; // To maintain stable sorting when frequencies are the same
        });
        return s;
    }
};