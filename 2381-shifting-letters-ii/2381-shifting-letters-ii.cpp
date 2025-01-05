class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> moves(n,0);
        for (auto& it:shifts){
            if (it[2]){
                moves[it[0]]++;
                if (it[1]+1 < n) moves[it[1]+1]--;
            }
            else{
                moves[it[0]]--;
                if (it[1]+1 < n) moves[it[1]+1]++;
            }
        }
        int numshift = 0;
        for (int i = 0; i < n; i++){
            numshift = (numshift+moves[i])%26;
            if (numshift < 0) numshift += 26;
            s[i] = 'a' + (s[i] - 'a' + numshift)%26;
        }
        return s;
    }
};