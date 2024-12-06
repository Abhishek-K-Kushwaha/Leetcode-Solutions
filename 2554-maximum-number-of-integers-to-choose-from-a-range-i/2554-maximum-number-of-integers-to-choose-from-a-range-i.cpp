class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,bool> ban;
        for (auto i:banned){
            ban[i] = 1;
        }
        int ans = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (ban[i]) continue;
            sum += i;
            if (sum <= maxSum) ans++;
            else break;
        }
        return ans;
    }
};