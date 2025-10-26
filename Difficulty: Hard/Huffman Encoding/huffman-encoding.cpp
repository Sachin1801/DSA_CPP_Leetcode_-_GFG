
class Node{
    public:
        int freq;
        string s;
        Node* left;
        Node* right; 
    
    Node(){
        left = nullptr;
        right = nullptr;
        freq = 0;
        s = "";
    }
    
    Node(int freq, string s){
        this->freq = freq;
        this->s = s;
        left = nullptr;
        right = nullptr;
    }
};

vector<string> preOrder(Node* root,string encoding, vector<string> &ans){
    if(!root) return ans;
    if(!root->left && !root->right){
        //we have got a single char node
        ans.push_back(encoding);
        return ans;
    }
    
    //follow preorder: root , left , right 
    //move left 
    // encoding.push_back('0');
    preOrder(root->left,encoding+'0',ans);
    preOrder(root->right,encoding +'1',ans);
    return ans;
}

class Solution {
  public:
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        // Code here
        
        auto cmp = [](Node*a ,Node* b){
            return a->freq > b->freq;
        };
        
        priority_queue<Node* , vector<Node*>, decltype(cmp)> minHeap(cmp);
        
        int n = f.size();
        for(int i =0; i<n;i++){
            Node *root = new Node(f[i],string(1,S[i]));
            minHeap.push(root);
        }
        
        // start forming the binary tree from bottom up
        while(minHeap.size()>1){
            Node *top1 = minHeap.top();
            minHeap.pop();
            Node *top2 = minHeap.top();
            minHeap.pop();
            
            // make the parent node
            Node *parent = new Node(top1->freq + top2->freq, top1->s + top2->s);
            //compare for left and right child
            parent->left = top1;
            parent->right = top2;
            minHeap.push(parent);
            
        }
        Node* root = minHeap.top();
        
        //in the end root will have the main parent containing all subtrees
        //now we have to perform pre-order traversal for single char strings
        vector<string> ans;
        string encoding ="";
        preOrder(root,encoding, ans);
        return ans;
        
    }
};