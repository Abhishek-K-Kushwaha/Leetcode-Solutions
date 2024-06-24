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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* evenhead = head->next;
        ListNode* oddtail;
        int cnt = 1;
        while(temp){
            ListNode* nxt = temp->next;
            ListNode* nxtnxt = nullptr;
            if (nxt) nxtnxt = temp->next->next;
            if (cnt%2 && (nxt == nullptr || nxtnxt == nullptr)) oddtail = temp;
            temp->next = nxtnxt;
            temp = nxt;
            cnt++;
        }
        oddtail->next = evenhead;
        return head;
    }
};