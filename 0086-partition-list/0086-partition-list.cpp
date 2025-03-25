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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* lhead =NULL, *rhead = NULL, *curr1 = NULL, *curr2 = NULL, *curr=head;

        while(curr!=NULL){
            if(curr->val < x){
                if(!lhead && !curr1){
                    lhead = curr;
                    curr1 = curr;
                    if(curr2!=NULL && curr2->next == curr){
                        curr2->next=NULL;
                    }
                }else{
                    if(curr2!= NULL && curr2->next==curr) curr2->next = NULL;
                    curr1->next = curr;
                    curr1 = curr;
                }
            }else{
                if(!rhead && !curr2){
                    rhead = curr;
                    curr2 = curr;
                    if(curr1!=NULL && curr1->next == curr) curr1->next = NULL;
                }else{
                    if(curr1!=NULL && curr1->next == curr) curr1->next = NULL;
                    curr2->next = curr;
                    curr2 = curr;
                }
            }
            curr = curr->next;
        }
        if(!lhead) return rhead;
        curr1->next = rhead;
        return lhead;
    }
};