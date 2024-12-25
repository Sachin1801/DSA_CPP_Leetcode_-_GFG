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

private:
    ListNode* find_middle(ListNode* head){
        ListNode* frunner = head->next;
        ListNode* runner = head;

        //find middle and high
        while(frunner!=NULL and frunner->next!=NULL){
            frunner = frunner->next->next;
            runner= runner->next;
        }
        return runner;
    }

    ListNode* Merge_two(ListNode* lefthead, ListNode* righthead){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(lefthead!=NULL and righthead!=NULL){
            if(lefthead->val <= righthead->val){
                temp->next = lefthead;
                temp = lefthead;
                lefthead = lefthead->next;
            }else{
                temp->next = righthead;
                temp = righthead;
                righthead = righthead->next;
            }
        }
        if(lefthead) temp->next = lefthead;
        else temp->next = righthead;

        return dummyNode->next;
    }

    ListNode* Merge_sort_LL(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* middle = find_middle(head);
        ListNode* lefthead= head;
        ListNode* righthead= middle->next;
        middle->next = NULL;
        lefthead = Merge_sort_LL(lefthead);
        righthead = Merge_sort_LL(righthead);
        return Merge_two(lefthead,righthead);
    }

public:
    ListNode* sortList(ListNode* head) {
        return Merge_sort_LL(head);
    }
};