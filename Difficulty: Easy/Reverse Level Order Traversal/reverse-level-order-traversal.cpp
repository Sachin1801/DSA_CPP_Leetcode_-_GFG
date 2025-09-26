/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<int> result;
        if(root == NULL )return result;
        if(root->left == NULL && root-> right == NULL) return {root->data};
        queue<Node*> q;
        q.push(root);
        // result.push_back(root->data);
        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            result.push_back(top->data);
            if(top->right) q.push(top->right);
            if(top->left){
                q.push(top->left);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};