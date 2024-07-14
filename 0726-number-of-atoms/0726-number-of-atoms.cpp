class Solution {
private:
    map<string, int> helper(string f, int& start) { 
        map<string, int> count;
        int i = start;
        while(i < f.size() && f[i] != ')') {
            if(f[i] == '(') {
                map<string, int> more = helper(f, ++i);
                int multiple = 0;
                while(i+1 < f.size() && f[i+1] >= '0' && f[i+1] <= '9'){
                    i++; // always point to the char we discuss
                    multiple = multiple * 10 + (f[i] - '0'); // handle 2-digits or larger number 
                }
                if(multiple == 0) { // no number shows if only 1 element 
                    multiple = 1;
                }
                for(auto ele: more) { // add the elements from (OH)2
                    ele.second = ele.second * multiple;
                    count[ele.first] += ele.second;
                }
            } else if(f[i] >= 'A' && f[i] <= 'Z') { // uppercase
                string atom = "";
                atom.push_back(f[i]);
                if(i+1 < f.size() && f[i+1] >= 'a') { // lowercase
                    i++; // point to the lowercase letter
                    atom.push_back(f[i]);
                }
                int multiple = 0;
                while(i+1 < f.size() && f[i+1] >= '0' && f[i+1] <= '9'){ 
                    i++;
                    multiple = multiple * 10 + (f[i] - '0');
                }
                if(multiple == 0) {
                    multiple = 1;           
                } 
                count[atom] += multiple;                            
            }
            i++;
        }
        start = i; // forward to the new index
        return count;
    }
public:
    string countOfAtoms(string formula) {
        string ans = "";
        int start = 0;
        map<string, int> count = helper(formula, start);
        for(auto ele: count) {
            ans += ele.first;
            if(ele.second > 1) {
                string tmp = to_string(ele.second);
                ans += tmp;
            }
        }

        return ans;
    }
};