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
    int f(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int dleft = f(root->left);
        int dright = f(root->right);
        if (dleft == -1 || dright == -1 || abs(dleft - dright) > 1)
            return -1;
        return 1 + max(dleft, dright);
    }

    bool isBalanced(TreeNode* root) {
        if (f(root) == -1)
            return false;
        else
            return true;
    }
};