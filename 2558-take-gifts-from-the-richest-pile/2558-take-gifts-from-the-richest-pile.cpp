class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        int ans = 0;
        for (int i : gifts) {
            ans += i;
            pq.push(i);
        }
        int m, n, s;
        for (k; k > 0; k--) {
            m = pq.top();
            // cout << m<< endl;
            pq.pop();
            s = sqrt(m);
            n = m - s;
            // cout<< n << endl;
            pq.push(m - n);
            ans -= (n);
        }
        return ans;
    }
};