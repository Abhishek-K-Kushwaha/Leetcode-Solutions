/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void f(Node* node, vector<int>& ans){
        if (node == nullptr) return;
        for (auto it:node->children){
            f(it, ans);
        }
        ans.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};