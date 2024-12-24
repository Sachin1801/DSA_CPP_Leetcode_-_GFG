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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        while(fast!=NULL and fast->next !=NULL){
            if(fast==slow and flag == true){
                ListNode* temp = head;
                while(temp!=slow){
                    temp = temp->next;
                    slow=slow->next;
                }
                return temp;
            }
            fast = fast->next->next;
            slow = slow->next;
            flag = true;
        }
        return NULL;
    }
};