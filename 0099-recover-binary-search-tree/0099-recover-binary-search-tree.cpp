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
    TreeNode* first = nullptr;
    TreeNode* second;
    TreeNode* prev = new TreeNode(INT_MIN);
    void inorder(TreeNode* root){
        if (root == nullptr) return;
        inorder(root->left);
        if (root->val < prev->val){
            if (first){
                second = root;
                return;
            }
            else{
                first = prev;
                second = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        cout<< first->val << " " << second->val << " ";
        swap(first->val, second->val);
    }
};