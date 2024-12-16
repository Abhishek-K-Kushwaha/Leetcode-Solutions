class Solution {
public:
    bool f(int d, int m, int k, int n, vector<int>& bloomDay){
        int cnt = 0, str = 0;
        //cout << d << endl;
        for (int i = 0; i < n; i++){
            if (bloomDay[i] <= d){
                str++;
                if (str == k){
                    str = 0;
                    cnt++;
                    //cout << "cnt= "<< cnt<< endl;
                    if (cnt == m) return true;
                }
            }
            else str = 0;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m*k > n) return -1;
        int l = 1, r = 1e9, mid;
        while (l < r){
            //cout << l << " "<< r<<endl;
            mid= (l+r)/2;
            if (f(mid, m, k, n, bloomDay)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};