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
    TreeNode* findLCA(TreeNode*root, TreeNode* p , TreeNode* q){
        if(!root) return NULL;

        if(root==p)
            return p;
        if(root==q) return q;
        TreeNode* left = findLCA(root->left,p,q);
        TreeNode* right = findLCA(root->right,p,q);
        if(right and !left) return right;
        if(!right and left) return left;
        if(right and left) return root;
        else return NULL;
        
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        
        return findLCA(root,p,q);
    }
};