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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> unique(nums.begin(),nums.end());

        ListNode *curr = head, *prev = new ListNode(-1,head) ;

        while(curr!=NULL){
            if(unique.find(curr->val) != unique.end()){
                // value is present we need to remove that
                //save the next node 
                prev->next = curr->next;

                ListNode* toDelete = curr;
                //remove the node from LL
                curr = prev->next;

                toDelete->next == NULL;
            }
            else{
                if(prev->val == -1){
                    head = curr;
                }
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};