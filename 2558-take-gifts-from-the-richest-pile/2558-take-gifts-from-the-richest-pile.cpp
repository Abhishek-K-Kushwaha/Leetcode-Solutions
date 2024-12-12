class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long ans = 0;
        for (int i : gifts) {
            ans += i;
            pq.push(i);
        }
        int m, n, s;
        for (k; k > 0; k--) {
            m = pq.top();
            pq.pop();
            s = sqrt(m);
            n = m - s;
            pq.push(s);
            ans -= (n);
        }
        return ans;
    }
};