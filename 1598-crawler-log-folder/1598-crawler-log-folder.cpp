class Solution {
public:
    int minOperations(vector<string>& logs) {
        int lvl = 0;
        for (auto& log : logs) {
            if (log == "../") {
                lvl = max(0, lvl - 1);
            } else if (log == "./") {
                continue;
            } else {
                lvl++;
            }
        }
        return lvl;
    }
};