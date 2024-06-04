class Solution {
public:
    void dfs(string& word, vector<vector<string>>& ans, string& beginWord, vector<string>& seq, unordered_map<string,int>& dict){
        if (word == beginWord) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int len = word.size();
        int lvl = dict[word];
        for (int i = 0; i < len; i++){
            char org = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if (dict.find(word) != dict.end() && dict[word] == lvl-1){
                    seq.push_back(word);
                    dfs(word,ans,beginWord,seq,dict);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> dict;
        unordered_set<string> lst(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        queue<string> q;
        q.push(beginWord);
        dict[beginWord] = 1;
        lst.erase(beginWord);
        int found = 0;
        int len = beginWord.size();
        while (!q.empty()){
            string word = q.front();
            int lvl = dict[word];
            if (word == endWord){
                found = 1;
                break;
            }
            q.pop();
            for (int i = 0; i < len; i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (lst.find(word) != lst.end()){
                        q.push(word);
                        lst.erase(word);
                        dict[word] = lvl+1;
                    }
                }
                word[i] = org;
            }
        }
        if (found) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, ans, beginWord,seq,dict);
        }
        return ans;
    }
};