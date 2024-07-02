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
    TreeNode* add(vector<int>& pre, int prest, int preend, 
                vector<int>& in, int inst, int inend, map<int,int>& ind){
        if (prest > preend || inst > inend) return nullptr;
        TreeNode* node = new TreeNode(pre[prest]);
        int i = ind[pre[prest]];
        int numsonleft = i - inst;
        node->left = add(pre, prest+1, prest + numsonleft, 
                        in, inst, i-1, ind);
        node->right = add(pre, prest+numsonleft+1, preend,
                        in, i+1, inend, ind);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> ind;
        int n = inorder.size();
        for (int i = 0; i < n; i++){
            ind[inorder[i]] = i;
        }
        TreeNode* root = add(preorder, 0, n-1, 
                            inorder, 0, n-1, ind);
        return root;
    }
};