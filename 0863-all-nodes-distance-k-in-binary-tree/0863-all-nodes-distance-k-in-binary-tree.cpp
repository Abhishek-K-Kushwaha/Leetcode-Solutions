/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        //parent[root] = nullptr;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == target)
                break;
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
        visited[target] = 1;
        q = {};
        q.push(target);
        int dist = 0;
        while (!q.empty()) {
            if (dist == k)
                break;
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
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};