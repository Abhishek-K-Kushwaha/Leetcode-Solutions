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
        vector<TreeNode*> preorder;
        stk.push(root);
        int cnt = 1;
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            preorder.push_back(node);
            cnt++;
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
        }
        preorder.push_back(nullptr);
        for (int i = 0; i < cnt - 1; i++) {
            preorder[i]->left = nullptr;
            preorder[i]->right = preorder[i + 1];
        }
    }
};