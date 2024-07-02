class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        for (int i : nums1) {
            dict[i]++;
        }
        vector<int> ans;
        for (int num : nums2) {
            if (dict[num]) {
                ans.push_back(num);
                dict[num]--;
            }
        }
        return ans;
    }
};