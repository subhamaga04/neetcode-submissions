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
        ListNode* prev = NULL;
        ListNode* curr = head; 
        ListNode* forward = NULL; 

        while(curr!= NULL){
            forward = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = forward; 
        }
        return prev; 
    }

    ListNode* re(ListNode* node){
        if(node == NULL){
            return NULL; 
        }

        ListNode* node1 = reverse(node); 
        node1->next = re(node1->next); 
        return node1; 
    }
    void reorderList(ListNode* head) {
        head -> next = re(head->next); 
    }
};
