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
    int ans =0;
    void sumNum(TreeNode* root, string curr){
        if(!root) return;
        curr+= to_string(root->val);
        if(!root->left && !root->right){
            ans += stoi(curr);
            return;
        }

        sumNum(root->left,curr);
        sumNum(root->right,curr);
    }
public:
    int sumNumbers(TreeNode* root) {
        string curr="";
        sumNum(root,curr);
        return ans;
    }
};