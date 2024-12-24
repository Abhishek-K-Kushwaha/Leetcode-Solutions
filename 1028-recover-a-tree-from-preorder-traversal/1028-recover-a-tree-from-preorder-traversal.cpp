/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i = 0;
    int dfs(string& s, int lvl, TreeNode* par, bool isright){
        string temp;
        while(i < s.size() && s[i] != '-'){
            temp.push_back(s[i]);
            i++;
        }
        int n = stoi(temp);
        TreeNode* node = new TreeNode(n);
        if (!isright) par->left = node;
        else par->right = node;
        if (i >= s.size()) return -1;
        int cnt = 0;
        while (s[i]=='-'){
            cnt++;
            i++;
        }
        if (cnt == lvl){
            cnt = dfs(s, lvl, par, 1);
        }
        if (cnt < lvl) return cnt;
        cnt = dfs(s, lvl+1, node, 0);
        if (cnt == lvl){
            return dfs(s, lvl, par, 1);
        }
        else return cnt;
    }

    TreeNode* recoverFromPreorder(string s) {
        string temp;
        while(i < s.size() && s[i] != '-'){
            temp.push_back(s[i]);
            i++;
        }
        int n = stoi(temp);
        TreeNode* root = new TreeNode(n);
        if (i < s.size()) {
            i++;
            dfs(s, 1, root, 0);
        }
        return root;
    }
};