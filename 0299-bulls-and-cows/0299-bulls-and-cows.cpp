class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,pair<int,int>> map; //secret, guess
        int n = guess.size();
        int bulls = 0;
        for (int i = 0; i < n; i++){
            if (secret[i] == guess[i]){
                bulls++;
            }
            else{
                map[secret[i]].first++;
                map[guess[i]].second++;
            }
        }
        int cows = 0;
        for (auto& it:map){
            cows += min(it.second.second, it.second.first);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};