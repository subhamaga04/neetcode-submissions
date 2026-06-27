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
    Node* copy(Node* head, unordered_map<Node*,Node*> &mp){
        Node* dummy = new Node(0); 
        Node* res = dummy; 
        Node* temp = head; 
        while(temp!= NULL){
            Node* node = new Node(temp->val); 
            mp[temp] = node; 
            res-> next = node; 
            temp = temp -> next; 
            res = res -> next; 
        }
        Node* copied_head = dummy-> next; 
        delete dummy; 
        return copied_head; 

    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp; 
        Node* copied_head = copy(head, mp); 
        Node* node = head; 
        while(node != NULL){
            if(node-> random == NULL){
                mp[node] -> random = NULL; 
            }else{
                mp[node] -> random = mp[node->random]; 
            }
            node = node -> next; 
        }
        return copied_head; 
    }
};
