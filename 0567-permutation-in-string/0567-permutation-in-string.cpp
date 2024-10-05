class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) return false;
        unordered_map<char,int> dict;
        for (char i: s1){
            dict[i]++;
        }
        // for (auto it:dict){
        //     cout<< it.first << " " << it.second << "\n";
        // }
        for (int i = 0; i < n1; i++){
            dict[s2[i]]--;
        }
        // for (auto it:dict){
        //     cout<< it.first << " " << it.second << "\n";
        // }
        for (int i = n1; i < n2; i++){
            bool flag = true;
        //     for (auto it:dict){
        //     cout<< it.first << " " << it.second << "\n";
        // }
            for (auto it:dict){
                if (it.second != 0){
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
            dict[s2[i-n1]]++;
            dict[s2[i]]--;
            //cout << endl;
        }
        bool flag = true;
        for (auto it:dict){
            if (it.second != 0){
                flag = false;
                break;
            }
        }
        //if (flag) return true;
        return flag;
    }
};