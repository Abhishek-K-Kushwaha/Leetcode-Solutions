class Solution {
public:
    bool isvowel(char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> presum(n);
        int cnt = 0;
        for (int i= 0; i < n; i++){
            cnt += (isvowel(words[i].back()) && isvowel(words[i][0]));
            presum[i] = cnt;
            //cout << cnt <<endl;
        }
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++){
            ans[i] = presum[queries[i][1]];
            if (queries[i][0]) ans[i] -= presum[queries[i][0]-1];
        }
        return ans;
    }
};