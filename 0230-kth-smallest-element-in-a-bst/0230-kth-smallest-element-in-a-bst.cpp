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
    bool inorder(TreeNode* node, int& count, int k, int& ans){
        if (node == nullptr) return false;
        if (inorder(node->left, count, k, ans)) return true;
        count++;
        if (count == k){
            ans = node->val;
            return true;
        }
        if (inorder(node->right, count, k, ans)) return true;
        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans;
        inorder(root, count, k, ans);
        return ans;
    }
};