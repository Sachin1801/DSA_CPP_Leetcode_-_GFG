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
    int calc_length(ListNode* head){
        int len = 0;
        ListNode* temp =head;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = calc_length(head);
        if(len == 1 and n ==1){
            return NULL;
        }
        if(n > len){
            return NULL;
        }
        if(n==len){
            ListNode* temp = head;
            head= head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex = head->next;
        int diff = len - n;
        while(diff--){
            prev = curr;
            curr = nex;
            nex = curr->next;
        }
        prev->next = nex;
        curr->next = NULL;
        delete curr;
        return head;
    }
};