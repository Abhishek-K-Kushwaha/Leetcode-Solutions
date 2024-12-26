class Solution {
public:
    int maxans = 0;
    bool possible(vector<vector<int>>& dict, int ind, vector<int>& bkt){
        for (int i = 0; i < 26; i++){
            if (dict[ind][i] > bkt[i]) return false; 
        }
        return true;
    }
    void addsub(vector<vector<int>>& dict, int ind, bool add, vector<int>& bkt){ 
        // 0- subtract, 1- add
        for (int i = 0; i < 26; i++){
            if (add) bkt[i] += (dict[ind][i]);
            else bkt[i] -= (dict[ind][i]);
        }
    } 

    void f(int i, vector<vector<int>>& dict, int ans, vector<int>& bkt){
        if (i == dict.size()) return;
        //for (int i = 0; i < dict.size(); i++){
            if (possible(dict,i, bkt)){
                ans += dict[i][26];
                maxans = max(ans, maxans);
                addsub(dict, i, 0, bkt); // subtracting
                f(i+1, dict, ans, bkt);
                addsub(dict, i, 1, bkt); // adding
                ans -= dict[i][26];
            }
            f(i+1, dict, ans, bkt);
        //}
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<vector<int>> dict(n, vector<int> (27,0));
        vector<int> bkt(26,0);
        int val;
        for (int i = 0; i < n; i++){
            val = 0;
            for (auto it:words[i]){
                dict[i][it-'a']++;
                val += score[it-'a'];
            }
            dict[i][26]=val;
        }
        for (auto it:letters){
            bkt[it-'a']++;
        }
        f(0, dict, 0, bkt);
        return maxans;
    }
};