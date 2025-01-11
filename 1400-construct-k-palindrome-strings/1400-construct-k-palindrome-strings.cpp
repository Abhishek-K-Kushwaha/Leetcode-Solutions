class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (k > n) return false;
        vector<int> freq(26,0);
        for (auto& c:s){
            freq[c-'a']++;
        }
        int odds = 0;
        for (int i:freq){
            if (i%2) odds++;
            if (odds > k) return false;
        }
        return true;

        //return false;
    }
};