//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
private:
    Node* store_parents(Node* root, unordered_map<Node*,Node*> &m,int k){
        if(!root)
            return nullptr;
        queue<Node*> q;
        q.push(root);
        m[root]=NULL;
        Node* targetnode = nullptr;
        while(!q.empty()){
            Node* node= q.front();
            if(node->data==k)
                targetnode = node;
            q.pop();
            if(node->left){
                q.push(node->left);
                m[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                m[node->right]=node;
            }
        }
        return targetnode;
    }
    
  public:
    int minTime(Node* root, int target) {
        // code here
        if(!root->left and !root->right and target==root->data) return 0;
        
        unordered_map<Node*,Node*> m;
        Node* tar=store_parents(root,m,target);
        int tim= 0;
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(tar);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* top = q.front();
                visited[top]=true;
                q.pop();
                if(top->left and !visited[top->left]) q.push(top->left);
                if(top->right and !visited[top->right]) q.push(top->right);
                if(m[top]!=NULL and !visited[m[top]]) q.push(m[top]);
            }
            tim++;
        }
        return tim-1;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends