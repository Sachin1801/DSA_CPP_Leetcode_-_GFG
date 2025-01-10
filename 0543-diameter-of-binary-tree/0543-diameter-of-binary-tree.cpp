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
    int find_diameter(TreeNode* root, int &diameter){
        if(!root) return 0;

        int left_height = find_diameter(root->left,diameter);
        int right_height = find_diameter(root->right,diameter);
        diameter = max(left_height+right_height, diameter);
        return 1 + max(left_height,right_height);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        find_diameter(root, diameter);
        return diameter;
    }
};