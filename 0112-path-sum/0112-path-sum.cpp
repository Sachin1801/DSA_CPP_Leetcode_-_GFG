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
    bool exist(TreeNode* root, int csum, int target){
        if(!root) return false;
        //if we are on leaf node
        csum += root->val;
        if(!root->left && !root->right){
            return csum == target;
        }

        //option 1: check on left
        return exist(root->left,csum,target) || exist(root->right,csum,target);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int csum = 0;
        return exist(root,csum,targetSum);
    }
};