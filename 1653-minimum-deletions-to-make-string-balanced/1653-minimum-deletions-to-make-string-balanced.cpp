class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int before = 0;
        int after = 0;
        //int ans = INT_MAX;
        for (auto& it: s){
            if (it == 'a') after++;
        }
        if (after == 0 || after == n) return 0;
        int ans = after ;
        for (int i = 0; i < n; i++){
            if (s[i] == 'a'){
                after--;
                ans = min(ans, before+after);
            }
            else{
                before++;
                ans = min(ans, before+after);
            }
        }
        return ans;        
    }
};