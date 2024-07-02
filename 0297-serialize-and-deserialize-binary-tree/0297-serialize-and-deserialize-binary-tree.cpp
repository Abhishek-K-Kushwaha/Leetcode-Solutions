/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                ans.append(to_string(node->val));
                ans.append(",");
                q.push(node->left);
                q.push(node->right);
            } else
                ans.append("n,");
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[0] == 'n')
            return nullptr;
        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "n")
                node->left = nullptr;
            else {
                TreeNode* l = new TreeNode(stoi(str));
                node->left = l;
                q.push(l);
            }

            getline(s, str, ',');
            if (str == "n")
                node->right = nullptr;
            else {
                TreeNode* r = new TreeNode(stoi(str));
                node->right = r;
                q.push(r);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));