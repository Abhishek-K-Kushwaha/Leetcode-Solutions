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
    int dfs(string& s, int lvl, TreeNode* par){
        string temp;
        while(i < s.size() && s[i] != '-'){
            temp.push_back(s[i]);
            i++;
        }
        int n = stoi(temp);
        //cout<<n<<endl;
        TreeNode* node = new TreeNode(n);
        par->left = node;
        if (i >= s.size()) return -1;
        int cnt = 0;
        while (s[i]=='-'){
            cnt++;
            i++;
        }
        if (cnt < lvl) return cnt;
        else if (cnt == lvl){
            string tempr;
            while(i < s.size() && s[i] != '-'){
                tempr.push_back(s[i]);
                i++;
            }
            n = stoi(tempr);
            TreeNode* noder = new TreeNode(n);
            par->right = noder;
            if (i >= s.size()) return -1;
            cnt = 0;
            while (s[i]=='-'){
                cnt++;
                i++;
            }
            if (cnt > lvl) return dfs(s, lvl+1, noder);
            else return cnt;
        }
        int z = dfs(s, lvl+1, node);
        if (z == lvl){
            string tempr;
            while(i < s.size() && s[i] != '-'){
                tempr.push_back(s[i]);
                i++;
            }
            n = stoi(tempr);
            TreeNode* noder = new TreeNode(n);
            par->right = noder;
            if (i >= s.size()) return -1;
            cnt = 0;
            while (s[i]=='-'){
                cnt++;
                i++;
            }
            if (cnt > lvl) return dfs(s, lvl+1, noder);
            else return cnt;
        }
        else return z;


    }
    TreeNode* recoverFromPreorder(string s) {
        string temp;
        while(i < s.size() && s[i] != '-'){
            temp.push_back(s[i]);
            i++;
        }
        int n = stoi(temp);
        //cout<<n<<endl;
        TreeNode* root = new TreeNode(n);
        if (i < s.size()) {
            i++;
            dfs(s, 1, root);
        }
        return root;
    }
};