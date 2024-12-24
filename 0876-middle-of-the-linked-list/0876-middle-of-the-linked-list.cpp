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
    ListNode* middleNode(ListNode* head) {
        ListNode* runner = head;
        ListNode* fastrunner = head;
        while(fastrunner!=NULL and fastrunner->next!=NULL){
            runner = runner->next;
            fastrunner = fastrunner->next->next;
        }
        return runner;
    }
};