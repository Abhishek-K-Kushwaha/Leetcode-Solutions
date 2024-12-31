class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0, ind = 1;
        int len = searchWord.size();
        bool flag = true;
        while (i < sentence.size()) {
            int j;
            flag = true;
            for (j = 0; j < len; j++) {
                if (sentence[i + j] != searchWord[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return ind;
            i += j;
            while (sentence[i] != ' ' && i < sentence.size()) {
                i++;
            }
            i++;
            ind++;
        }
        return -1;
    }
};