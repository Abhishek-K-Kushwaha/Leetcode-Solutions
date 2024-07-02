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
    TreeNode* add(vector<int>& post, int postst, int postend, 
                vector<int>& in, int inst, int inend, map<int,int>& ind){
        if (postst > postend || inst > inend) return nullptr;
        TreeNode* node = new TreeNode(post[postend]);
        int i = ind[post[postend]];
        int numsonright = inend - i;
        node->left = add(post, postst, postend-numsonright-1, 
                        in, inst, i-1, ind);
        node->right = add(post, postend-numsonright, postend-1,
                        in, i+1, inend, ind);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> ind;
        int n = inorder.size();
        for (int i = 0; i < n; i++){
            ind[inorder[i]] = i;
        }
        TreeNode* root = add(postorder, 0, n-1, inorder, 0, n-1, ind);
        return root;
    }
};