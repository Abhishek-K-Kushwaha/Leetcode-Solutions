class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int i, j, k, temp, ans = 0;
        for (int x = 0; x < n; x++){
            i = x;  
            for (int y = x+1; y < n; y++){
                j = y;
                while (j < n && s[i] != s[j]){
                    j++;
                }
                if (j == n) break;
                y = j;
                for (int z = y+1; z <n; z++){
                    k = z;
                    j = y;
                    i = x;
                    while (k < n && s[i] != s[k]){
                        k++;
                    }
                    //cout << i << j << k << endl;
                    if (k == n) break;
                    z = k;
                    int cnt = 0;
                    while (k < n && s[i] == s[j] && s[i] == s[k]){
                        cnt++; i++; j++; k++;
                        if (s[i-1] != s[i]) break;
                    }
                    ans = max(ans, cnt);
                    //cout<< cnt << endl;
                }
            }
        }
        if (ans) return ans;
        else return -1;
    }
};