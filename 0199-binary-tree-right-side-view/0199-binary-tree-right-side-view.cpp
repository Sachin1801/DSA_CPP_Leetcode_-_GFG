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
    void store_right_view(TreeNode* root, map<int,int> &m, int row, int col){
        if(!root) return;

        if(m.find(row)==m.end()){
            m[row]=root->val;
        }
        //else{
        //     auto pair = m[row];
        //     if(pair.second < col){
        //         m[row]={root->val,col};
        //     }
        // }
        if(root->right)
            store_right_view(root->right,m,row+1,col+1);
        
        store_right_view(root->left,m,row+1,col-1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};

        map<int,int> m;
        store_right_view(root,m,0,0);

        vector<int> ans;
        for(const auto &pair: m){
            ans.push_back(pair.second);
        }
        return ans;
    }
};