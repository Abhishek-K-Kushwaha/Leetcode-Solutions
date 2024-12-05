class Solution {
public:
    bool canChange(string start, string target) {
        int len = start.size();
        int i = 0, j = 0;
        while (i < len || j < len) {
            while (i < len && start[i] == '_') {
                i++;
            }
            while (j < len && target[j] == '_') {
                j++;
            }
            // if (i < len && j >= len)
            //     return false;
            // if (j < len && i >= len)
            //     return false;
            //if (i < len && j < len) {
                if (start[i] != target[j])
                    return false;
                else {
                    if (start[i] == 'L' && j > i)
                        return false;
                    else if (start[i] == 'R' && j < i)
                        return false;
                }
            //}
            i++;
            j++;
        }
        // while (i < len) {
        //     if (start[i] != '_')
        //         return false;
        //     i++;
        // }
        // while (j < len) {
        //     if (target[j] != '_')
        //         return false;
        //     j++;
        // }
        return true;
    }
};