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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        store_inorder(root,inorder);
        if(k> inorder.size())
            return -1;
        return inorder[k-1];

        
    }
};