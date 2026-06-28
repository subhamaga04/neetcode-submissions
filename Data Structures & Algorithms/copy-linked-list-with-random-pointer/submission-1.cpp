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
    Node* copy(Node* head){
        Node* temp = head; 
        while(temp!= NULL){
            Node* node = new Node(temp->val); 
            node->next = temp->next; 
            temp->next = node; 
            temp = node->next; 
    
        }
        return head; 

    }
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL; 
        copy(head); 
        Node* node1 = head; 
        Node* node2 = head->next; 
        while(node1 != NULL){
            if(node1->random == NULL){
                node2->random = NULL; 
            }else{
                node2 -> random = node1->random->next; 
            }
            node1 = node1->next->next; 
            if(node2->next!=NULL) node2 = node2->next->next; 
        }

        Node* node3 = head; 
        Node* node4 = head->next; 
        Node* copied_head = head->next; 
        while(node3!=NULL){
            node3 -> next = node3-> next-> next; 
            node3 = node3-> next; 
            if(node4->next != NULL){
                node4 -> next = node4-> next-> next; 
                node4 = node4-> next; 
            }
        }

        return copied_head; 
    }
};
