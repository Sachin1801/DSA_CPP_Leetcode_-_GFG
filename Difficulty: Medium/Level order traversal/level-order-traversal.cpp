/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        
        //getting the nbrs for the next level, before we move ahead 
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int currSize = q.size();
            vector<int> tempLevel; 
            for(int i=0;i<currSize;i++){
                //if we have left and right child 
                Node* temp = q.front();
                q.pop();
                tempLevel.push_back(temp->data);
                if(temp->left!= NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            ans.push_back(tempLevel);
        }
        return ans;
    }
};