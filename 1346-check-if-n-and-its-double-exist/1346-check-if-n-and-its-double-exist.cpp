class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for (int i:arr){
            if (i%2 == 0){
                if (st.find(i/2) != st.end()) return true;
            }
            if (st.find(i*2) != st.end()) return true;
            st.insert(i);
        }
        return false;
    }
};