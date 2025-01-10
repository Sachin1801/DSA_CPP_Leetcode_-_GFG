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
    void store_elem(TreeNode* root,map<int,vector<pair<int,int>>> &m, int row, int col)
    {
        if(root==NULL)
            return;
        m[col].push_back({row,root->val});
        store_elem(root->left,m,row+1,col-1);    
        store_elem(root->right,m,row+1, col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> m;
        store_elem(root,m,0,0);
        for(const auto &p: m){
            vector<pair<int,int>> temp = p.second;
            sort(temp.begin(),temp.end(), [](const pair<int,int> &p1, const pair<int,int> &p2){
                if(p1.first==p2.first)
                    return p1.second < p2.second;
                return p1.first < p2.first;
            });
            vector<int> col_values;
            for( const auto &pai: temp){
                col_values.push_back(pai.second);
            }
            ans.push_back(col_values);
        }
        return ans;
    }
};