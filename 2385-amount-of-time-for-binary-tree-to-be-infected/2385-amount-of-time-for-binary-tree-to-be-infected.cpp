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
    int amountOfTime(TreeNode* root, int target) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* start;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == target){
                start = node;
                break;
            }
            if (node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
        unordered_map<TreeNode*, int> visited;
        visited[start] = 1;
        q = {};
        q.push(start);
        int dist = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = 1;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = 1;
                }
                if (parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]] = 1;
                }
            }
            dist++;
        }
        return dist - 1;
    }
};