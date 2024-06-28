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
    int f(TreeNode* root, int& maxdia){
        if (root == nullptr)
            return 0;
        int dleft = f(root->left, maxdia);
        int dright = f(root->right, maxdia);
        maxdia = max(maxdia, dright + dleft);
        return 1 + max(dleft, dright);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        f(root, diameter);
        return diameter;
    }
};