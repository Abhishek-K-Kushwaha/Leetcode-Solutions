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
    unordered_map<TreeNode*,TreeNode*> parent;
    vector<TreeNode*> leafs;
    bool inorder(TreeNode* node){
        if (node == nullptr) return false;
        if (!node->left && !node->right) leafs.push_back(node);
        if (inorder(node->left)) parent[node->left] = node;
        if (inorder(node->right)) parent[node->right] = node;
        return true;
    }

    void dfs(TreeNode* node, unordered_set<TreeNode*>& vis, int dist, int& range, int& ans){
        if (dist > range || node == nullptr) return;
        vis.insert(node);
        if (dist && !node->left && !node->right) ans++;
        if (vis.find(node->left) == vis.end()) dfs(node->left, vis, dist+1, range, ans);
        if (vis.find(node->right) == vis.end()) dfs(node->right, vis, dist+1, range, ans);     
        if (vis.find(parent[node]) == vis.end()) dfs(parent[node], vis, dist+1, range, ans);   
    }

    int countPairs(TreeNode* root, int distance) {
        inorder(root);
        unordered_set<TreeNode*> vis; 
        int ans = 0;
        for (auto it:leafs){
            //vis.insert(it);
            dfs(it, vis, 0, distance, ans);
            vis.clear();            
        }
        return ans/2;
    }
};