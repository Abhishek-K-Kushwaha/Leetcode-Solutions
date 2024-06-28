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
    int f(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int dleft = f(node->left);
        int dright = f(node->right);
        return 1 + max(dleft, dright);
    }
    int maxDepth(TreeNode* root) { 
        return f(root); 
    }
};