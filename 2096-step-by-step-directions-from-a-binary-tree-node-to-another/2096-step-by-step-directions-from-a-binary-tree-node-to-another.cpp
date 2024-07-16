/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool preorder(TreeNode* node, string& ans, int tar) {
        if (node == nullptr)
            return false;
        if (node->val == tar)
            return true;

        ans.push_back('L');
        if (preorder(node->left, ans, tar))
            return true;
        ans.pop_back();

        ans.push_back('R');
        if (preorder(node->right, ans, tar))
            return true;
        ans.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string src = "";
        string dst = "";
        preorder(root, src, startValue);
        preorder(root, dst, destValue);
        int i = 0;
        int n = src.size();
        int m = dst.size();
        while (i < min(n, m)) {
            if (src[i] == dst[i]) {
                i++;
            } else
                break;
        }
        int len = i;
        // while (i < n) {
        //     src[i] = 'U';
        //     i++;
        // }
        return string(n - len, 'U') + dst.substr(len, m - len);
    }
};