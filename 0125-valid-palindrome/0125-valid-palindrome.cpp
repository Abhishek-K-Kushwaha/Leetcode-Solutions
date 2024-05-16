class Solution {
public:
    bool isPalindrome(string str) {
        int start  = 0;
        int end = str.size() - 1;
        while (start < end){
            if (!isalnum(str[start])) {
                start++;
                continue;
            }
            if (!isalnum(str[end])){
                end--;
                continue;
            }
            if (tolower(str[start]) != tolower(str[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};