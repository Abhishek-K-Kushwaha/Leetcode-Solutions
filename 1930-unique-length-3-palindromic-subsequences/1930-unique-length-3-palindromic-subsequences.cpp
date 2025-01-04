class Solution {
public:
    int f(string& s, int fst, int lst){
        vector<int> present(26, 0);
        int cnt = 0;
        for (int i = fst+1; i < lst; i++){
            if (!present[s[i]-'a']){
                cnt++;
                present[s[i]-'a'] = 1;
            }
        }
        return cnt;
    }
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26,-1);
        vector<int> last(26);
        int ans = 0, ind = 0;
        for (auto it:s){
            if (first[it-'a'] == -1) first[it-'a'] = ind;
            last[it-'a'] = ind;
            ind++;
        }
        for (int i = 0; i < 26; i++){
            if (first[i] != -1 && last[i] != first[i]){
                ans += f(s, first[i], last[i]);
            }
        }
        return ans;
    }
};