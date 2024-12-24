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
        ListNode* frunner = head;
        ListNode* runner = head;
        while(frunner!=NULL and frunner->next!=NULL ){
            frunner = frunner->next->next;
            runner= runner->next;
            if(frunner==runner){
                return true;
            }
        }
        return false;
    }
};