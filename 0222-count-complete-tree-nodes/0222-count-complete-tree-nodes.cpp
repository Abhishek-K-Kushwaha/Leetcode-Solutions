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
    int leftHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }
    int rightHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l = leftHeight(root);
        if (l == rightHeight(root))
            return (1 << l) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};