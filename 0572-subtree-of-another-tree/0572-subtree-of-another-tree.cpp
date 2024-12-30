/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    bool check(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        else if(p==NULL || q==NULL) return false;

        //check for current node and if true 
        //check for left and right subtree recursively
        return (p->val == q->val) && check(p->left,q->left) && check(p->right,q->right);
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;

        return check(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot) ;
    }
};