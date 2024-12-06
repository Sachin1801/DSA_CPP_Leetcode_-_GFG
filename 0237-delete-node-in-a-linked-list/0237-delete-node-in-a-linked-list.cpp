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
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* Next = node->next;
        while(Next->next!=NULL){
            swap(curr->val,Next->val);
            curr = Next;
            Next = Next->next;
        }
        swap(curr->val,Next->val);
        curr->next = NULL;
        delete Next;
        return;
    }
};