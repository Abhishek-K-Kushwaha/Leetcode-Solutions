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
    TreeNode* reverseOddLevels(TreeNode* root) {
        //vector<int> val;
        if (root->left == nullptr) return root;
        queue<TreeNode*> q;
        queue<TreeNode*> revq;
        q.push(root->left); revq.push(root->right);
        int lvl = 1, cnt = 0, num;
        TreeNode* temp;
        TreeNode* revtemp;
        while (q.front() != nullptr){
            temp = q.front();
            revtemp = revq.front();
            q.pop(); revq.pop();
            q.push(temp->left);
            q.push(temp->right);
            revq.push(revtemp->right);
            revq.push(revtemp->left);
            //cout<< lvl << endl;
            
            if (lvl % 2){
                //val.push_back(temp->val);
                //cout << temp->val <<" "<< revtemp->val<< endl;
                num = temp->val;
                temp->val = revtemp->val;
                revtemp->val = num;
            }
            cnt += 4;
            if (cnt == pow(2,lvl+1)){
                lvl++;
                cnt = 0;
            }
        } 
        return root;
    }
};