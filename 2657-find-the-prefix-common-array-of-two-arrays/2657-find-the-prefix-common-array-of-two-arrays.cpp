class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (freq[A[i]])
                cnt++;
            else
                freq[A[i]] = 1;
            if (freq[B[i]])
                cnt++;
            else
                freq[B[i]] = 1;
            ans[i] = cnt;
        }
        return ans;
    }
};