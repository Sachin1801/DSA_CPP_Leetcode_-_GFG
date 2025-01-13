/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        queue<TreeNode* > q;
        q.push(root);
        string serial="";
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(top==nullptr){
                serial+="null,";
            }
            else{
                q.push(top->left);
                q.push(top->right);
                serial += to_string(top->val)+",";
            }
        }
        serial.pop_back();
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        stringstream s(data);
        string str;
        queue<TreeNode*> q;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="null"){
                top->left=NULL;
            }else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                top->left = leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="null"){
                top->right=NULL;
            }else{
                TreeNode* rightnode = new TreeNode(stoi(str));
                top->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));