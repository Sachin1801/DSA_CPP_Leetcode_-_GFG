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
        auto cmp = [](ListNode *n1, ListNode *n2){
            return n1->val > n2->val;
        };
        priority_queue<ListNode*,vector<ListNode*>, decltype(cmp)> q(cmp);
        for(auto* listhead: lists){
            if(listhead)
                q.push(listhead);
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        while(!q.empty()){
            ListNode* curr = q.top();
            q.pop();
            temp->next = curr;
            temp = curr;
            if(curr->next)
                q.push(curr->next);
        }
        return newHead->next;
    }
};