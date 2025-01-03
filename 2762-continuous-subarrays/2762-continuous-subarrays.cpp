class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = nums.size(), n = ans;
        int l = 0, r = 1, len;
        multiset<int> st; 
        st.insert(nums[0]);
        while (r < n){
            //cout << l << " " << r << endl;
            while (r < n && abs(nums[r]-*st.begin())<=2 && abs(nums[r]-*st.rbegin())<=2){
                st.insert(nums[r]);
                r++;
                //cout << r << endl;
            }
            len = r - l;
            ans += (len*(len-1))/2;
            //cout << ans << "ans" << endl;
            while (l<r && r<n && ((abs(nums[r]-*st.begin())>2) || (abs(nums[r]-*st.rbegin())>2))){
                auto it = st.find(nums[l]);
                // cout << "TO be del " << *it<< endl;
                st.erase(it);
                // for (auto i: st){
                //     cout << i << " ";
                // }
                l++;
                //cout << endl << "l = " << l << endl;
            }
            if (r<n) st.insert(nums[r]);
            r++;
        }
        return ans;
    }
};