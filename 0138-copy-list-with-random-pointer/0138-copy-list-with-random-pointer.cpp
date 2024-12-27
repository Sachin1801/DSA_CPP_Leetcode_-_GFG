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
        unordered_map<Node*,Node*> m;
        Node* temp = head;
        Node* dummy = new Node(-1);
        while(temp!=NULL){
            m[temp]= new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            Node* curr = m[temp];
            curr->next = m[temp->next];
            curr->random = m[temp->random];
            temp = temp->next;
        }
        return m[head];
    }
};