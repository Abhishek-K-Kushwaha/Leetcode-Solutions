class Solution {
public:
    //vector<int> r(9,0);
    
    int ans = 0;
    void put(int r, int n, vector<bool>& c, vector<bool>& d, vector<bool>& invd){
        //cout << r<< endl;
        if (r == n){
            ans++;
            return;
        }
        //int x, y;
        for (int i = 0; i < n; i++){
            if (!c[i] && !d[r+i] && !invd[r-i+8]){
                //cout<<"yes\n";
                c[i] = 1, d[r+i] = 1 , invd[r-i+8] = 1;
                put(r+1, n, c, d, invd);
                c[i] = 0, d[r+i] = 0 , invd[r-i+8] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<bool> c(9,0);
        vector<bool> d(17,0); //i = sum-1 /-shaped
        vector<bool> invd(17,0); //i = diff+7 \-shaped 
        put(0, n, c, d, invd);
        return ans;
    }
};