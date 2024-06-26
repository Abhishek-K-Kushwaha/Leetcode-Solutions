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
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* headofhead = new ListNode(-1);
        ListNode* temp = head->next;
        ListNode* last = headofhead;
        ListNode* node = head;
        // int num = head->data;
        int cnt = 1;
        while (temp) {
            if (temp->val == node->val) {
                cnt++;
            } else {
                if (cnt == 1) {
                    last->next = node;
                    last = last->next;
                }
                node = temp;
                cnt = 1;
            }
            temp = temp->next;
        }
        if (cnt == 1) {
            last->next = node;
            last = last->next;
        }
        last->next = nullptr;
        return headofhead->next;
    }
};