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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    bool reverse = true; //if true-> before element else next element
    void pushAll(TreeNode* node){
        while (node){
            stk.push(node);
            if (reverse) node = node->right;
            else node = node->left;
        }
    }
    BSTIterator(TreeNode* root, bool isreverse) {
        reverse = isreverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if (reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator before(root, true);
        BSTIterator after(root, false);
        int i = after.next(); // smallest element
        int j = before.next(); // largest element
        //cout<< i << " " << j << " | ";
        while (i < j){
            //cout<< i << " " << j << " | ";
            if (i + j == k) return true;
            else if (i + j > k) i = before.next();
            else j = after.next();
        }
        return false;
    }
};