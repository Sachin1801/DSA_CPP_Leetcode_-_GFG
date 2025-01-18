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
    TreeNode* findlastchild(TreeNode* root){
        while(root->right!=NULL) root=root->right;
        return root;
    }

    TreeNode* helper(TreeNode* root){
        if(!root->left) return root->right;
        else if(!root->right) return root->left;

        TreeNode* right = root->right;
        TreeNode* lastchild = findlastchild(root->left);
        lastchild->right= right;
        return root->left;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key)
            return helper(root);
        TreeNode* dummy = root;
        while(root){
            if(root->val > key){
                if(root->left!=NULL and root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root=root->left;
                }
            }else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};