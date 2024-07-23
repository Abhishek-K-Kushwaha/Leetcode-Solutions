class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(201);
        for (auto i : nums) {
            cnt[i + 100]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (cnt[a + 100] == cnt[b + 100])
                return a > b;
            return cnt[a + 100] < cnt[b + 100];
        });
        return nums;
    }
};