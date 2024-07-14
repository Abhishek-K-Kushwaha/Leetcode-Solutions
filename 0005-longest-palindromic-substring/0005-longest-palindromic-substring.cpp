class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        int len = 1;
        int start = 0;
        //int maxj;
        for (int ind = 1; ind < n-1; ind++){
            if (s[ind-1] == s[ind+1]){
                int i = ind-2;
                int j = ind+2;
                while (i >= 0 && j < n && s[i] == s[j]){
                    i--;
                    j++;
                }
                if (j-i-1 > len){
                    start = i+1;
                    // maxj = j-1;
                    len = j-i-1;
                }
            }
            if (s[ind] == s[ind-1]){
                int i = ind-2;
                int j = ind+1;
                while (i >= 0 && j < n && s[i] == s[j]){
                    i--;
                    j++;
                }
                if (j-i-1 > len){
                    start = i+1;
                    // maxj = j-1;
                    len = j-i-1;
                }
            }
        }
        if (len == 1 && s[n-2] == s[n-1]){
            start = n-2;
            len = 2;
        }
        return s.substr(start, len);
    }
};