class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for (auto it : nums){
            if (it > 0 && it <= n){
                st.insert(it);
            }
        }
        for (int i = 1; i <= n; i++){
            if (st.find(i) == st.end()) return i;
        }
        return n+1;
    }
};