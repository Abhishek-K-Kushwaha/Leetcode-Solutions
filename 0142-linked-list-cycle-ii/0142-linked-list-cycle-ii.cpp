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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        int flag = 0;
        while (fast && fast->next) {
            if (fast == slow){
                flag = 1;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        if (flag == 0) return nullptr;
        slow = head;
        fast = fast->next;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};