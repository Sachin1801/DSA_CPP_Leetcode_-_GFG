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
private:
    TreeNode* first= nullptr, *second = nullptr,*prev = nullptr;

    void recover_helper(TreeNode* root){
        //base case
        if(!root){
            return;
        }
        recover_helper(root->left);
        if(prev && prev->val > root->val){
            if(!first) first = prev; // first violation
            second = root;
        }
        prev = root ; 
        recover_helper(root->right);
    }

public:

    void recoverTree(TreeNode* root) {
        if(!root) return ;
        recover_helper(root);
        if(first && second) swap(first->val, second->val);
    }
};