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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* temp = head->next;
        ListNode* last = head;
        while (temp){
            if (temp->val != last->val){
                last->next = temp;
                last = temp;
            }
            temp = temp->next;
        }
        last->next = nullptr;
        return head;
    }
};