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
    TreeNode* f(TreeNode* root){
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        TreeNode* node = root->left;
        while (node->right){
            node = node->right;
        }
        node->right = root->right;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root; 
        TreeNode* node = root;
        if (node->val == key){
            return f(root);
        }
        while (node){
            if (node->val > key){
                if (node->left && node->left->val == key){
                    node->left = f(node->left);
                    break;
                }
                else{
                    node = node->left;
                }
            }
            else{
                if (node->right && node->right->val == key){
                    node->right = f(node->right);
                    break;
                }
                else{
                    node = node->right;
                }
            }
        }
        return root; 
    }
};