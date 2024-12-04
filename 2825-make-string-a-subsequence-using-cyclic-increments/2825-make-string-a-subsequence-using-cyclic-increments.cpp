class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        int i = 0, j = 0;
        while (j < len1){
            if (i == len2) return true;
            if (str2[i] == str1[j] || str2[i] - str1[j] == 1){
                i++;
            }
            else if (str2[i] == 'a' && str1[j] == 'z'){
                i++;
            }
            j++;
        }
        if (i == len2) return true;
        return false;
    }
};