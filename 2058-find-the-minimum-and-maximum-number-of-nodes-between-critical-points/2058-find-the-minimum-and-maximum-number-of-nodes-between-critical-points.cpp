/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* node = head->next;
        ListNode* first = nullptr;
        int prev = head->val;
        while (node->next){
            if ((prev < node->val && node->val > node->next->val) || 
                (prev > node->val && node->val < node->next->val)){
                first = node;
                break;
            }
            prev = node->val;
            node = node->next;
        }
        if (first == nullptr) return {-1,-1};
        node = first->next;
        prev = first->val;
        int mind = INT_MAX;
        int maxd = 0;
        int dist = 0;
        while(node->next){
            dist++;
            if ((prev < node->val && node->val > node->next->val) || 
                (prev > node->val && node->val < node->next->val)){
                mind = min(mind, dist);
                maxd += dist;
                dist = 0;
            }
            prev = node->val;
            node = node->next;            
        }
        if (mind == INT_MAX) return {-1,-1};
        else return {mind, maxd};
    }
};