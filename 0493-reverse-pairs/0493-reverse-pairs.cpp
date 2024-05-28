class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        int count = 0;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += counter(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] > nums[right]) {
                temp.push_back(nums[right++]);
            } else {
                temp.push_back(nums[left++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    int counter(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int right = mid + 1;
        for (int left = low; left <= mid; left++) {
            while (right <= high && nums[left] > (long long)2 * nums[right])
                right++;
            count += (right - mid - 1);
        }
        return count;
    }
};