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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        int carry = 0;
        while (temp1 && temp2) {
            int sum = temp1->val + temp2->val + carry;
            ListNode* node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;
            carry = sum / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1) {
            int sum = temp1->val + carry;
            ListNode* node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;
            carry = sum / 10;
            temp1 = temp1->next;
        }
        while (temp2) {
            int sum = temp2->val + carry;
            ListNode* node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;
            carry = sum / 10;
            temp2 = temp2->next;
        }
        if (carry) {
            ListNode* last = new ListNode(carry);
            curr->next = last;
        }
        return head->next;
    }
};