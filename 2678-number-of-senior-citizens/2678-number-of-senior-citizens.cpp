class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& it:details){
            string age = it.substr(11,2);
            if (stoi(age) > 60) ans++;
        }
        return ans;
    }
};