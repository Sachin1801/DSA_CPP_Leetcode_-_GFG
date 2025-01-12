/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void parent_level_order(TreeNode* root,
                            unordered_map<TreeNode*, TreeNode*> &m) {
        queue<TreeNode*> q;
        q.push(root);
        m[root] = NULL ;
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if (top->left) {
                q.push(top->left);
                m[top->left] = top;
            }
            if (top->right) {
                q.push(top->right);
                m[top->right] = top;
            }
        }
        return;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*, TreeNode*> m;
        parent_level_order(root, m);

        int dist = 0;
        vector<int> ans;
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        while (dist < k) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                visited[node] = true;
                if (node->left and !visited[node->left])
                    q.push(node->left);
                if (node->right and !visited[node->right])
                    q.push(node->right);
                if (m[node] != NULL and !visited[m[node]])
                    q.push(m[node]);
            }
            dist++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};