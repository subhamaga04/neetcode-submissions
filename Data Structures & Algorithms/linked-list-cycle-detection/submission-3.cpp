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
    bool hasCycle(ListNode *head) {
        ListNode* n1 = head; 
        ListNode* n2 = head; 
        if(head == NULL || head->next == NULL){
            return false; 
        } 

        while(n1!= NULL && n2!= NULL){
            if(n2->next == NULL){
                return false; 
            }
            n2 = n2->next->next; 
            n1 = n1->next; 
            if(n1 == n2){
                return true; 
            }
        }
        return false; 
    }
};