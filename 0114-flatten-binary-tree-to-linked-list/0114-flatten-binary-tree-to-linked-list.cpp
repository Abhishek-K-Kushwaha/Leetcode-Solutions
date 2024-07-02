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
        while (true) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
            node->left = nullptr;
            if (!stk.empty()) {
                node->right = stk.top();
            }
            else{ 
                node->right = nullptr;
                break;
            }
        }
    }
};