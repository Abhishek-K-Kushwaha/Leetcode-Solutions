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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        int h = 1;
        while (true){
            if (l == nullptr && r == nullptr){
                return (1<<h) - 1;
            }
            if (l == nullptr || r == nullptr){
                break;
            }
            l = l->left;
            r = r->right;
            h++;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};