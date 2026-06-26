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
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* merge_alternate(ListNode* head, ListNode* node) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        ListNode* node1 = head;
        bool lr = true;
        while (node1 != NULL && node != NULL) {
            if (lr) {
                temp->next = node1;
                node1 = node1->next;
            }else {
                temp->next = node;
                node = node->next;
            }
            temp = temp->next;
            lr = !lr;
        }
        if(node1 != NULL){
            temp -> next = node1; 
        }else{
            temp -> next = node; 
        }

        head = dummy->next;
        delete dummy;
        return head;
    }

    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return; 
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* first = head;

        second = reverse(second);
        head = merge_alternate(first, second);
    }
};