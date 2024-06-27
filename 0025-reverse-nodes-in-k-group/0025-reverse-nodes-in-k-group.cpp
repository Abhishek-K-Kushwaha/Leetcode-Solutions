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
    ListNode* reverse(ListNode* head){
        if (head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while (temp){
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* khead = head;
        ListNode* lasttail = new ListNode(-1);
        int len = 1;
        while (temp){
            if (len % k == 0){
                ListNode* nxt = temp->next;
                temp->next = nullptr;
                lasttail->next = reverse(khead);
                if (len == k) head = lasttail->next;
                lasttail = khead;
                temp = nxt;
                khead = nxt;
            }
            else{
                temp = temp->next;
            }
            len++;
        }
        lasttail->next = khead;
        return head;
    }
};