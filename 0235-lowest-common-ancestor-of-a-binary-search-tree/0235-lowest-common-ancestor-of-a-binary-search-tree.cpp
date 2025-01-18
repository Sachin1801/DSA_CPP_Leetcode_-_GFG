/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val){
            ans = root;
            lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val < p->val && root->val < q->val){
            ans = root;
            lowestCommonAncestor(root->right,p,q);
        }
        else if(root->val == p->val or root->val == q->val){
            ans = root->val == p->val ? p: q;
        }
        //both are on different sides of the subtree
        else 
            ans = root;
        return ans;
    }
};