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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* runner = head;
        ListNode* fastrunner = head;
        while(fastrunner!=NULL and fastrunner->next!=NULL){
            runner = runner->next;
            fastrunner = fastrunner->next->next;
        }
        return runner;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* middle = middleNode(head);
        middle = reverseList(middle);
        ListNode* temp = middle;
        ListNode* temp2 = head;
        while(temp2!=middle and temp!=NULL){
            if(temp2->val!=temp->val)
                return false;
            temp2 = temp2->next;
            temp = temp->next;
        }
        return true;
    }
};