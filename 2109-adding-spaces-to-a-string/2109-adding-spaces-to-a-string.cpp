class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int len = s.size();
        int num = spaces.size();
        string ans;
        int ind = 0;
        for (int i = 0; i < len; i++){
            if (ind < num && i == spaces[ind]){
                ans+=' ';
                ind++;
            }
            ans += s[i];
        }
        return ans;
    }
};