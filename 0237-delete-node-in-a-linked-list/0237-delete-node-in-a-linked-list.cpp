/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int data = node->next->val;
        ListNode *nxt = node->next->next;
        delete node->next;
        node->val = data;
        node->next = nxt;
    }
};