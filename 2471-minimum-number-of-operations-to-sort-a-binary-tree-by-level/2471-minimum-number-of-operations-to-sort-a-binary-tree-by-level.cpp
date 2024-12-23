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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()){
            int n = q.size();
            vector<pair<int,int>> arr(n);
            vector<int> vis(n, 0);
            for (int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                arr[i] = {node->val, i};
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            sort(arr.begin(), arr.end());
            for (int i = 0; i < n; i++){
                if (!vis[i]){
                    //int cnt = 0;
                    vis[i] = 1;
                    int ind = i;
                    while (!vis[arr[ind].second]){
                        ans++;
                        vis[arr[ind].second] = 1;
                        ind = arr[ind].second;
                    }
                    //ans += cnt;
                }
            }
        }
        return ans;
    }
};