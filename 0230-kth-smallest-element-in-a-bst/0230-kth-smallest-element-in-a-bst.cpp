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
    int f(TreeNode* root, int& cnt, int k){
        if (root == nullptr) return 0;

        int m = f(root->left, cnt, k);
        if (m) return m;

        cnt++;
        if (cnt == k) return root->val;

        m = f(root->right, cnt, k);
        if (m) return m;

        return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return f(root, cnt, k);
    }
};