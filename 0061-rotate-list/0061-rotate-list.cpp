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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* tail = NULL;
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            tail = temp;
            temp = temp->next;
            len++;
        }
        if(k%len==0) return head;
        int steps  = len - (k%len);
        temp = head;
        while(steps>1){
            temp = temp->next;
            steps--;
        }
        ListNode* nhead= temp->next;
        temp->next = NULL;
        tail->next = head;
        return nhead;
    }
};