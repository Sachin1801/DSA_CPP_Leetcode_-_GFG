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
    TreeNode* create_bst(vector<int> &preorder, int up, int &i){
        if(i==preorder.size() || preorder[i]>up) return NULL;
        TreeNode* n = new TreeNode(preorder[i++]);
        n->left = create_bst(preorder,n->val,i);
        n->right = create_bst(preorder,up,i);
        return n;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        return create_bst(preorder,INT_MAX,i);
    }
};