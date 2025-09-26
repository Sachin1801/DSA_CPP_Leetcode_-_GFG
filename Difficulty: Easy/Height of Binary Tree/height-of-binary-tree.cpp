/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* node) {
        // code here
        int ans =0;
        if(node == NULL) return 0;
        if(node->left ==NULL and node->right == NULL) return 0;
        
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            int lvlSize = q.size();
            for(int i=0; i< lvlSize;i++){
                Node* top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            ans++;
        }
        return ans-1;
    }
};