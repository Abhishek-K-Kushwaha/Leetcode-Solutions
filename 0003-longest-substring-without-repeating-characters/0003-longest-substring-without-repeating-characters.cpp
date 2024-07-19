class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char,int> st;
        while (j < n){
            if (st.find(s[j]) != st.end()){
                ans = max(ans, j - i);
                ans = max(ans, j - st[s[j]]);
                while (s[i] != s[j]){
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                i++;
            }
            st[s[j]] = j;
            j++;
        }
        ans = max(ans, (int)st.size());
        return ans;
    }
};