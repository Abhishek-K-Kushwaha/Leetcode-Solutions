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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node = head->next;
        ListNode* last = head;
        int sum = 0;
        while (node){
            if (node->val){
                sum += node->val;
            }
            else{
                node->val = sum;
                sum = 0;
                last->next = node;
                last = node;
            }
            node = node->next;
        }
        last->next = nullptr;
        return head->next;

    }
};