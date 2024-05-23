class Solution {
public:
    int subarraySum(vector<int>& arr, int K) {
        int N = arr.size();
        unordered_map<int, int> dict;
        int count = 0;
        int pre_sum = 0;
        for (int i = 0; i < N; i++) {
            pre_sum += arr[i];
            if (pre_sum == K) {
                count++;
            }
            if (dict.find(pre_sum - K) != dict.end()) {
                count += dict[pre_sum - K];
            }
            // if (dict.find(pre_sum) == dict.end())
            //     dict[pre_sum] = 1;
            // else
            //     dict[pre_sum]++;
            dict[pre_sum]++;
        }
        return count;
    }
};