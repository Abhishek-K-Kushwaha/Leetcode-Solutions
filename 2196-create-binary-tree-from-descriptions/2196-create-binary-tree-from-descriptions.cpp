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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<TreeNode*,bool>> dict; // value->node,ischild
        for (auto& it:descriptions){
            TreeNode* parent; 
            TreeNode* child;
            if (dict.find(it[0]) == dict.end()){ 
                parent = new TreeNode(it[0]);
                dict[it[0]] = {parent,false};
            }
            else parent = dict[it[0]].first;
            if (dict.find(it[1]) == dict.end()) {
                child = new TreeNode(it[1]);
                dict[it[1]] = {child, true};
            }
            else {
                child = dict[it[1]].first;
                dict[it[1]].second = true;
            }
            if (it[2]) parent->left = child;
            else parent->right = child;
        }
        for (auto& it: dict){
            if (it.second.second == false) return it.second.first;
        }
        return nullptr;
    }
};