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
class FindElements {
private:
    queue<TreeNode*> q;
    unordered_set<int> s;
    // 1,1,1,1,1,0,0 
public:
    FindElements(TreeNode* root) {
        if(!root) return;
        root->val = 0;
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            s.insert(top->val);

            if(top->left){
                top->left->val = (2*top->val) +1 ;
                q.push(top->left);
            }
            if(top->right){
                top->right->val = (2*top->val)+2;
                q.push(top->right);
            }
        }    
    }
    
    bool find(int target) {
        return s.find(target)!=s.end() ? true : false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */