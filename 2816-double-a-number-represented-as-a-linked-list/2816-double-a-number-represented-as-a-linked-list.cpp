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
    int f(ListNode* node){
        if (node == nullptr){
            return 0;
        }
        int carry = f(node->next);
        int num = node->val;
        num = 2 * num + carry;
        node->val = num % 10;
        return (num)/10;
    }

    ListNode* doubleIt(ListNode* head) {
        if (f(head)){
            ListNode* front = new ListNode(1, head);
            return front;
        }
        return head;
    }
};