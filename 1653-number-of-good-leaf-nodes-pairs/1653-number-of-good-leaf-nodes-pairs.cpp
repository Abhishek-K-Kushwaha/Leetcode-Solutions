class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        return postOrder(root, distance)[11];
    }
    
private:
    vector<int> postOrder(TreeNode* node, int distance) {
        if (!node) return vector<int>(12, 0);
        if (!node->left && !node->right) {
            vector<int> current(12, 0);
            current[0] = 1;
            return current;
        }
        
        vector<int> left = postOrder(node->left, distance);
        vector<int> right = postOrder(node->right, distance);
        
        vector<int> current(12, 0);
        
        for (int i = 0; i < 10; i++) {
            current[i + 1] += left[i] + right[i];
        }
        
        current[11] += left[11] + right[11];
        
        for (int d1 = 0; d1 <= distance; d1++) {
            for (int d2 = 0; d2 <= distance; d2++) {
                if (2 + d1 + d2 <= distance) {
                    current[11] += left[d1] * right[d2];
                }
            }
        }
        
        return current;
    }
};