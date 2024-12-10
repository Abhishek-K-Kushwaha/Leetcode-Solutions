class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int i, j, k, ans = 0;
        //int temp = -1;
        for (int x = 0; x < n; x++){
            i = x;  
            int temp = -1;
            for (int y = x+1; y < n; y++){
                j = y;
                if (y <= temp) continue;
                while (j < n && s[i] != s[j]){
                    j++;
                }
                if (j == n) break;
                temp = j;
                for (int z = temp+1; z <n; z++){
                    k = z;
                    j = temp;
                    i = x;
                    while (k < n && s[i] != s[k]){
                        k++;
                    }
                    cout << i << j << k << endl;
                    if (k == n) break;
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