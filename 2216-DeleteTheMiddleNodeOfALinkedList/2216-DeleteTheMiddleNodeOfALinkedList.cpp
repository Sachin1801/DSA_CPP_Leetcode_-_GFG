// Last updated: 12/14/2025, 4:16:57 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL) return NULL;

        ListNode* prev= NULL;
        ListNode* curr = head;
        ListNode* runner = head;
        while(runner!=NULL and runner->next!=NULL){
            prev = curr;
            curr = curr->next;
            runner = runner->next->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        return head;
    }
};