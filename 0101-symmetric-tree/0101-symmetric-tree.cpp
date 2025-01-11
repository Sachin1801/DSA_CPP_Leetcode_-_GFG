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
    bool checkSymmetry(TreeNode* leftnode, TreeNode* rightnode){
        if(!leftnode and !rightnode) return true;
        if(!leftnode || !rightnode) return false;

        return (leftnode->val==rightnode->val) and checkSymmetry(leftnode->left,rightnode->right) and checkSymmetry(leftnode->right,rightnode->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return checkSymmetry(root->left,root->right);
    }
};