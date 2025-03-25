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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *prev = NULL, *curr = head, *nex = head->next;

        while (curr!= NULL && curr->next != NULL) {
            if (curr->val != nex->val) {
                prev = curr;
                curr = nex;
                nex = curr->next;
            } else {
                while (nex != NULL && curr->val == nex->val) {
                    nex = nex->next;
                }
                curr = nex;
                if(curr && curr->next) nex = curr->next;
                if (prev != NULL)
                    prev->next = curr;
                else
                    head = curr;
            }
        }
        return head;
    }
};