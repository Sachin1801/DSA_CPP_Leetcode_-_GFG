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
    set<int> s;
private:
    void store_inorder(TreeNode* root, vector<int> &inorder,bool &flag){
        if(!root) return ;
        store_inorder(root->left,inorder,flag);
        if(s.find(root->val)!=s.end()){
            flag = false;
            return;
        }
        inorder.push_back(root->val);
        store_inorder(root->right,inorder,flag);
        return ;
    }

public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left and !root->right)) return true;
        vector<int> inorder;
        bool flag = true;
        store_inorder(root,inorder,flag);
        if(!flag) return false;
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1]) return false;
        }
        return true;
    }
};