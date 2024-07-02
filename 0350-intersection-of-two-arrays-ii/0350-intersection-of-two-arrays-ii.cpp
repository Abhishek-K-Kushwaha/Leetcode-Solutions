class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dict(1001);
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