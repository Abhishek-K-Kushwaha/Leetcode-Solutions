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
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while (temp) {
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* mid = head;
        while (fast->next && fast->next->next) {
            mid = mid->next;
            fast = fast->next->next;
        }
        fast = reverse(mid->next);
        ListNode* front = head;
        while (fast) {
            if (fast->val != front->val) {
                return false;
            }
            fast = fast->next;
            front = front->next;
        }
        return true;
    }
};