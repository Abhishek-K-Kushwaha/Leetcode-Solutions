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
    ListNode* findMiddle(ListNode* head){
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* temp1, ListNode* temp2) {
        ListNode* temp = new ListNode(-1);
        ListNode* headofhead = temp;
        while (temp1 && temp2){
            if (temp1->val < temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 == nullptr){
            temp->next = temp2;
        }
        else{
            temp->next = temp1;
        }
        return headofhead->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* mid = findMiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = mid->next;
        mid->next = nullptr;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return merge(lefthead, righthead);
    }
};