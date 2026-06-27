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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); 
        ListNode* temp = dummy; 
        int carry = 0; 
        int val1 = 0; 
        int val2 = 0; 

        while(l1!= NULL || l2!= NULL || carry > 0){
            if(l1!=NULL) val1 = l1->val; 
            else val1 = 0; 
            
            if(l2!=NULL) val2 = l2->val; 
            else val2 = 0; 

            int node_value = val1 + val2 + carry; 
            ListNode* node = new ListNode(node_value%10); 
            temp-> next = node; 
            carry = node_value/10; 
            if(l1!=NULL) l1 = l1->next; 
            if(l2!=NULL) l2 = l2->next;
            temp = temp->next; 
        }

        ListNode *head = dummy -> next; 
        delete dummy; 
        return head; 
    }
};
