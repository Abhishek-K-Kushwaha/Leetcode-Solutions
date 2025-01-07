class Solution {
public:
    bool f(string& s, string& st){
        //cout << st << " " << s << endl;
        int n = s.size(), inds = 0, indst;
        for (int i = 0; i < st.size(); i++){
            indst = i;
            inds = 0;
            //cout << indst << " " << inds << endl;
            while (indst < st.size() && inds < n && st[indst] == s[inds]){
                inds++; indst++;
                //cout<< "yes" << endl;
            }
            if (inds == s.size()){ 
                //cout << "T" << endl;
                return true;
            }
        }
        //cout << "F" << endl;
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (words[i].size() < words[j].size() && f(words[i], words[j])){ 
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};