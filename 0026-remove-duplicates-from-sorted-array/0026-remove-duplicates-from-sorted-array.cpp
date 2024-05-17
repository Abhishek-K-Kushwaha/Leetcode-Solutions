class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int ind;
        int flag = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1] && !flag) {
                ind = i;
                flag = 1;
            }
            if (arr[i] > arr[i - 1] && flag) {
                arr[ind] = arr[i];
                ind++;
            }
        }
        if (flag)
            return ind;
        else
            return n;
    }
};