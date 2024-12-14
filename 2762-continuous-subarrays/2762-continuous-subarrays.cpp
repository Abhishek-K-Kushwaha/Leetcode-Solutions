#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        deque<int> minDeque, maxDeque; // To track min and max in the window
        int l = 0;

        for (int r = 0; r < n; ++r) {
            // Maintain minDeque for the minimum value
            while (!minDeque.empty() && nums[minDeque.back()] > nums[r]) {
                minDeque.pop_back();
            }
            minDeque.push_back(r);

            // Maintain maxDeque for the maximum value
            while (!maxDeque.empty() && nums[maxDeque.back()] < nums[r]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(r);

            // Shrink the window if the difference exceeds 2
            while (!minDeque.empty() && !maxDeque.empty() &&
                   nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (minDeque.front() == l) minDeque.pop_front();
                if (maxDeque.front() == l) maxDeque.pop_front();
                ++l;
            }

            // Add the number of valid subarrays ending at r
            ans += (r - l + 1);
        }

        return ans;
    }
};
