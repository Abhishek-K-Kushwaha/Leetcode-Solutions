class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        int n = plant.size();
        vector<int> ind(n);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int a, int b){
            return grow[a] > grow[b];
        });
        int ans = 0, p = 0;
        for (int i:ind){
            p += plant[i];
            ans = max(ans, p + grow[i]);
        }
        return ans;
    }
};