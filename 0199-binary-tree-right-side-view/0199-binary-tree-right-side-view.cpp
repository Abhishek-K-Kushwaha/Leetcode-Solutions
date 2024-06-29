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
    void f(TreeNode* node, int lvl, vector<int>& ans){
        if (node == nullptr) return;
        if (lvl == ans.size()) ans.push_back(node->val);
        f(node->right, lvl + 1, ans);
        f(node->left, lvl + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        f(root, 0, ans);
        return ans;
    }
};