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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>, greater<int>> q;
        for(auto listhead: lists){
            ListNode* temp = listhead;
            while(temp!=NULL){
                q.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        while(!q.empty()){
            int value = q.top();
            q.pop();
            ListNode* n = new ListNode(value);
            temp->next = n;
            temp = n;
        }
        return newHead->next;
    }
};