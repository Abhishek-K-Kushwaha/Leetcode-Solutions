class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& it:details){
            // string age = it.substr(11,2);
            int age = 0;
            for (int i = 11; i < 13; i++){
                age = age*10 + (it[i]-'0');
            }
            if (age > 60) ans++;
        }
        return ans;
    }
};