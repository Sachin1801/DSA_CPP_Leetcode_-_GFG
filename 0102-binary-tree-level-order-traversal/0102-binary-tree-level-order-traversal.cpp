/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp!=NULL){
                    if(temp->left!=NULL) q.push(temp->left);
                    if(temp->right!=NULL) q.push(temp->right);
                    v.push_back(temp->val);
                }
            }
            ans.push_back(v);         
        }
        return ans;
    }
};