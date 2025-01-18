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
    void store_inorder(TreeNode* root, int &cnt, int k, int &ans){
        if(!root || cnt >= k) return ;
        store_inorder(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
         store_inorder(root->right,cnt,k,ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        int cnt=0;
        int ans = 0;
        store_inorder(root,cnt,k,ans);
        return ans;
        

        
    }
};