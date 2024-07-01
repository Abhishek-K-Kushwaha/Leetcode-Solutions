/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        int lastmaxind = 0;
        int maxind = 0;
        while (!q.empty()) {
            int len = q.size();
            lastmaxind = maxind;
            maxind = INT_MIN;
            int minind = INT_MAX;
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front().first;
                int ind = q.front().second;
                q.pop();
                minind = min(ind, minind);
                maxind = max(ind, maxind);
                if (node->left)
                    q.push({node->left, ind * 2 - lastmaxind});
                if (node->right)
                    q.push({node->right, ind * 2 + 1 - lastmaxind});
            }
            ans = max(ans, maxind - minind + 1);
        }
        return ans;
    }
};