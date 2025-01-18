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
    vector<int> store_inorder(TreeNode* root, vector<int> &inorder){
        if(!root) return inorder;
        store_inorder(root->left,inorder);
        inorder.push_back(root->val);
        store_inorder(root->right,inorder);
        return inorder;
    }

public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left and !root->right)) return true;
        vector<int> inorder;
        store_inorder(root,inorder);
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1]) return false;
        }
        return true;
    }
};