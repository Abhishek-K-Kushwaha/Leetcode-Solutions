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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //if (!headA || !headB) return nullptr;
        ListNode* tempa = headA;
        ListNode* tempb = headB;
        while (tempa != tempb) {
            tempa = tempa ? tempa->next : headB;
            tempb = tempb ? tempb->next : headA;
        }
        return tempa;
    }
};