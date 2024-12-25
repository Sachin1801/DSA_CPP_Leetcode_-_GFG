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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> visited;
        ListNode* temp= headA;
        while(temp){
            visited[temp]=true;
            temp = temp->next;
        }
        temp = headB;
        while(temp!=NULL){
            if(visited[temp]==true) return temp;
            temp = temp->next;
        }
        return NULL;
    }
};