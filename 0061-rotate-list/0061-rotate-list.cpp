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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        int len = 0;
        while (temp){
            len++;
            if (temp->next) temp = temp->next;
            else break;
        }
        k = k % len;
        if (k == 0) return head;
        ListNode* newtail = head;
        int cnt = 0;
        while (cnt != len - k - 1){
            cnt++;
            newtail = newtail->next;
        }
        ListNode* newhead = newtail->next;
        newtail->next = nullptr;
        temp->next = head;
        return newhead;
    }
};