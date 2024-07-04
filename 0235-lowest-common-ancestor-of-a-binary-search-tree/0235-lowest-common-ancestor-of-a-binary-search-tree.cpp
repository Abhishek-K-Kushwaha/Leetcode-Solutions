/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small, big;
        if (p->val > q->val) {
            small = q->val;
            big = p->val;
        } else {
            small = p->val;
            big = q->val;
        }

        TreeNode* node = root;
        while (true) {
            if (node->val == small || node->val == big)
                return node;
            if (node->val > small && node->val < big)
                return node;
            else if (node->val < small)
                node = node->right;
            else
                node = node->left;
        }
        return nullptr;
    }
};