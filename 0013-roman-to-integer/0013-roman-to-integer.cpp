class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char,int> dict;
        dict['I'] = 1; dict['V'] = 5; dict['X'] = 10; dict['L'] = 50; 
        dict['C'] = 100; dict['D'] = 500; dict['M'] = 1000;
        int i = 0;
        while (i < n){
            if (dict[s[i]] < dict[s[i+1]]) ans -= dict[s[i]];
            else ans += dict[s[i]];
            i++; 
        }
        return ans;
    }
};