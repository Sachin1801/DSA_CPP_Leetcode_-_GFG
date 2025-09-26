/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
private:

    int max_height(Node* root, int& res){
        if(!root) return 0;
        
        //if node has left tree
        int leftHeight=max_height(root->left, res);
        int rightHeight=max_height(root->right,res);

        res = max(res,leftHeight+rightHeight);
        
        return max(leftHeight,rightHeight)+ 1;
    }
    
  public:
    int diameter(Node* root) {
        // Your code here
        // ) return 0;
        
        int res=0;
        max_height(root,res);
        return res;
    }
};