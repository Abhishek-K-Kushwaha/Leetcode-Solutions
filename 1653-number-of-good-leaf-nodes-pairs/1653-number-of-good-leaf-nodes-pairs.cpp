class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leafNodes;

        traverseTree(root, nullptr, graph, leafNodes);

        int ans = 0;
        for (TreeNode* leaf : leafNodes) {
            queue<TreeNode*> bfsQueue;
            unordered_set<TreeNode*> seen;
            bfsQueue.push(leaf);
            seen.insert(leaf);

            for (int i = 0; i <= distance; i++) {
                int size = bfsQueue.size();
                for (int j = 0; j < size; j++) {
                    TreeNode* currNode = bfsQueue.front();
                    bfsQueue.pop();
                    if (leafNodes.count(currNode) && currNode != leaf) {
                        ans++;
                    }
                    if (graph.count(currNode)) {
                        for (TreeNode* neighbor : graph[currNode]) {
                            if (!seen.count(neighbor)) {
                                bfsQueue.push(neighbor);
                                seen.insert(neighbor);
                            }
                        }
                    }
                }
            }
        }
        return ans / 2;
    }

private:
    void traverseTree(TreeNode* currNode, TreeNode* prevNode, 
                      unordered_map<TreeNode*, vector<TreeNode*>>& graph, 
                      unordered_set<TreeNode*>& leafNodes) {
        if (!currNode) return;
        if (!currNode->left && !currNode->right) {
            leafNodes.insert(currNode);
        }
        if (prevNode) {
            graph[prevNode].push_back(currNode);
            graph[currNode].push_back(prevNode);
        }
        traverseTree(currNode->left, currNode, graph, leafNodes);
        traverseTree(currNode->right, currNode, graph, leafNodes);
    }
};