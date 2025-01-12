class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> open;
        stack<int> both;
        int n = s.size();
        if (n % 2) return false;
        for (int i = 0; i < n; i++){
            if (locked[i] == '0'){
                both.push(i);
            }
            else if (s[i] == '('){
                open.push(i);
                //cout << 2 << endl;
            }
            else{
                //cout << 3 << endl;
                if (!open.empty()){
                    open.pop();
                }
                else if (!both.empty()){
                    both.pop();
                }
                else return false;
            }
        }
        //int both = 0;
        while (!both.empty() && !open.empty() && open.top() < both.top()){
            both.pop();
            open.pop();
        }
        if (!open.empty()) return false;
        return true;
    }
};