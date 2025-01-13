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
    int pre_idx=0;
    unordered_map<int,int> m;
private:
    TreeNode* dfs(vector<int>& preorder, int st, int end){
        if(st>end) return nullptr;
        int root_val = preorder[pre_idx++];
        int mid = m[root_val];
        TreeNode* root = new TreeNode(root_val);
        root->left = dfs(preorder,st,mid-1);
        root->right = dfs(preorder,mid+1,end);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0)
            return nullptr;
        
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return dfs(preorder,0,inorder.size()-1);

    }
};