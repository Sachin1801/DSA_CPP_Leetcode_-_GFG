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

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int carry =0;
        while(l1 and l2){
            int sum = l1->val + l2->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            l1 = l1->next;
            carry = sum /10;
        }
        while(l2){
            int sum = l2->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            l2 = l2->next;
            carry = sum /10;
        }
        if(carry == 1) temp->next = new ListNode(carry);
        temp= head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
};