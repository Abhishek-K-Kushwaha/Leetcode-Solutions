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
    void f(TreeNode* root, int& cnt, int k, int& ans){
        if (root == nullptr) return;
        f(root->left, cnt, k, ans);
        cnt++;
        if (cnt == k){ 
            ans = root->val;
            return;
        }
        f(root->right, cnt, k, ans);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans;
        f(root, cnt, k, ans);
        return ans;
    }
};