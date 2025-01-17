class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool ans = true;
        for (int i : derived) {
            ans ^= i;
        }
        return ans;
    }
};