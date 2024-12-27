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

    ListNode* findkth(ListNode* head, int k){

        while(k>1 and head!=NULL){
            head = head->next;
            k--;
        }
        return head;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next == NULL )return head;
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        bool first = false;
        while(temp != NULL){
            ListNode* kthNode = findkth(temp,k);
            if(!kthNode){
                if(prevNode){
                    prevNode->next = temp;
                    break;
                }
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next =NULL;
            kthNode = reverseList(temp);
            if(temp==head)
                head = kthNode;
            else
                prevNode->next = kthNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};