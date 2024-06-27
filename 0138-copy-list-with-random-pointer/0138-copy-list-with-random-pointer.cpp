/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        Node* temp = head;
        while (temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }
        temp = head;
        while (temp){
            if (temp->random){
                temp->next->random = temp->random->next;
            }
            else{
                temp->next->random = nullptr;
            }
            temp = temp->next->next;
        }
        Node* copyhead = head->next;
        temp = head;
        while(temp->next){
            Node* nxt = temp->next;
            temp->next = temp->next->next;
            temp = nxt;
        }
        return copyhead;
    }
};