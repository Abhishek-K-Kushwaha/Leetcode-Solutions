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
    int range;
    int ans = 0;
    vector<int> postorder(TreeNode* node) {
        if (node == nullptr)
            return vector<int>(11, 0);
        if (!node->left && !node->right) {
            vector<int> leafs(11, 0);
            leafs[0] = 1;
            return leafs;
        }
        vector<int> l = postorder(node->left);
        vector<int> r = postorder(node->right);

        for (int i = 0; i <= range; i++) {
            for (int j = 0; j <= (range - i - 2); j++) {
                ans += l[i] * r[j];
            }
        }
        for (int i = 9; i >= 0; i--) {
            l[i + 1] = l[i] + r[i];
        }
        l[0] = 0;
        return l;
    }
    int countPairs(TreeNode* root, int distance) {
        range = distance;
        postorder(root);
        return ans;
    }
};