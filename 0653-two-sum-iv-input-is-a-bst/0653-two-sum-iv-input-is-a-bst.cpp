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
    vector<int> inorder;

    void store_inorder(TreeNode* root){
        if(!root) return;
        store_inorder(root->left);
        inorder.push_back(root->val);
        store_inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        store_inorder(root);
        int i=0,j=inorder.size()-1;
        while(i<j){
            int sum = inorder[j] + inorder[i];
            if(sum==k)
                return true;
            else if(sum<k)
                i++;
            else
                j--;
        }
        return false;
    }
};