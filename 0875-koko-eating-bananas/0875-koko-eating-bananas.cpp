class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end()), mid, cnt;
        while (l < r){
            mid = (l + r)/ 2;
            cnt = 0;
            for (int i:piles){
                cnt += (1+(i-1)/mid);
            }
            if (cnt <= h) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};