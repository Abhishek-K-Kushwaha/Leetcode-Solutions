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
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev = new TreeNode(-1);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            prev->right = node;
            prev->left = nullptr;
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
            prev = node;
        }
        prev->right = nullptr;
    }
};