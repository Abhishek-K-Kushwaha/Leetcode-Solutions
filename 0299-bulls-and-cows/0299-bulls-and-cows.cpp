class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> smap;
        unordered_map<char,int> gmap;
        int n = guess.size();
        int bulls = 0;
        for (int i = 0; i < n; i++){
            if (secret[i] == guess[i]){
                bulls++;
            }
            else{
                smap[secret[i]]++;
                gmap[guess[i]]++;
            }
        }
        int cows = 0;
        for (auto& it:smap){
            cows += min(it.second, gmap[it.first]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};