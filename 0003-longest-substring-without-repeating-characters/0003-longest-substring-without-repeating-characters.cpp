class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char,int> st;
        while (j < n){
            if (st.find(s[j]) == st.end()){
                st[s[j]] = j;
                j++;
            }
            else{
                ans = max(ans, j - i);
                ans = max(ans, j - st[s[j]]);
                //cout<< ans << " " << i << " " << j <<"\n";
                while (s[i] != s[j]){
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                st[s[j]] = j;
                i++;
                j++;

            }
        }
        //cout << st.size() << "\n";
        // for (auto it:st){
        //     cout << it.first << " " << it.second << " ";
        // }
        ans = max(ans, (int)st.size());
        return ans;
    }
};