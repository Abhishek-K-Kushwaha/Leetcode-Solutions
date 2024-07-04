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
    bool f(TreeNode* node, long long min, long long max){
        if (node == nullptr) return true;
        if (node->val > max || node->val < min) return false;
        //bool ans = true;
        bool ans = f(node->left, min, (long long) node->val-1);
        if (!ans) return false;
        ans = ans & f(node->right,(long long) node->val+1, max);
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        return f(root, INT_MIN, INT_MAX);
    }
};