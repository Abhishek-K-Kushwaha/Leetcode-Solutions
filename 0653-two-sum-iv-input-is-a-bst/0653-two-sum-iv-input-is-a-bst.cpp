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
    bool findSecond(TreeNode* root, int target, TreeNode* first){
        while(root){
            if (root->val == target && root != first) return true;
            else if (root->val > target) root = root->left;
            else root = root->right;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* first = stk.top();
            stk.pop();
            if (findSecond(root, k - first->val, first)) return true;
            if (first->left) stk.push(first->left);
            if (first->right) stk.push(first->right);
        }
        return false;
    }
};