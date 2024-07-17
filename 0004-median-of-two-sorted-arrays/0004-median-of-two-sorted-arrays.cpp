class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m + n == 1) {
            if (m) return nums1[0];
            return nums2[0];
        }
        int i = 0;
        int j = 0;
        double ans1 = 1e9;
        double ans2 = 1e9;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                i++;
                if ((m + n + 1) / 2 == i + j) {
                    ans1 = nums1[i - 1];
                    break;
                }
            } else {
                j++;
                if ((m + n + 1) / 2 == i + j) {
                    ans1 = nums2[j - 1];
                    break;
                }
            }
        }

        if (j >= n) {
            if (ans1 == 1e9)
                ans1 = nums1[(m + n + 1) / 2 - j - 1];
            ans2 = nums1[(m + n + 1) / 2 - j];
        } else if (i >= m) {
            if (ans1 == 1e9)
                ans1 = nums2[(m + n + 1) / 2 - i - 1];
            ans2 = nums2[(m + n + 1) / 2 - i];
        }

        if ((m + n) % 2)
            return ans1;
        if (ans2 != 1e9)
            return (ans1 + ans2) / 2;
        else {
            ans2 = min(nums1[i], nums2[j]);
            return (ans1 + ans2) / 2;
        }
    }
};