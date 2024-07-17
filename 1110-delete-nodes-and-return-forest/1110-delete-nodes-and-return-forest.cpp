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
    void postorder(TreeNode* node, unordered_set<int>& del, vector<TreeNode*>& ans){
        if (node == nullptr) return;
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        postorder(l, del, ans);
        postorder(r, del, ans);
        if (l && (del.find(l->val) != del.end())){
            node->left = nullptr;
            // if (l->left) ans.push_back(l->left);
            // if (l->right) ans.push_back(l->right);
        }
        if (r && (del.find(r->val) != del.end())){
            node->right = nullptr;
            // ans.push_back(r);
        }
        if (del.find(node->val) != del.end()){
            if (node->left) ans.push_back(node->left);
            if (node->right) ans.push_back(node->right);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del;
        for (auto i: to_delete){
            del.insert(i);
        }
        vector<TreeNode*> ans;
        postorder(root, del, ans);
        if (del.find(root->val) == del.end()) ans.push_back(root);
        return ans;
    }
};