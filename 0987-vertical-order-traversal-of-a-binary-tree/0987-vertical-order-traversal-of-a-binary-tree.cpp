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
    void createmap(TreeNode* node, int col, int lvl, int& mincol, int& maxcol, unordered_map<int, multiset<pair<int, int>>>& dict){
        if (node == nullptr) return;
        mincol = min(mincol, col);
        maxcol = max(maxcol, col);
        dict[col].insert({lvl, node->val});
        createmap(node->left, col-1, lvl+ 1, mincol, maxcol, dict);
        createmap(node->right, col+1, lvl+1, mincol, maxcol, dict);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, multiset<pair<int, int>>> dict; //{col-> {lvl, value}}
        int mincol = 0;
        int maxcol = 0;
        createmap(root, 0, 0, mincol, maxcol, dict);
        int numcol = maxcol - mincol + 1;
        vector<vector<int>> ans(numcol);
        for (int i = mincol; i <= maxcol; i++){
            int col = i - mincol;
            for (auto j:dict[i]){
                ans[col].push_back(j.second);
            }
        }
        return ans;
    }
};