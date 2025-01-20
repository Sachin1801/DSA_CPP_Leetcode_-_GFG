//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
 
//  Tree node structure  used in the program

// struct Node {
//     int data;
//     Node *left;
//     Node *right;
    

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

class NodeValue {
public:
    int size;
    int maxnode;
    int minnode;

    NodeValue(int size, int maxval, int minval) : size(size), maxnode(maxval), minnode(minval) {}
};

class Solution {
private:
    NodeValue compute(Node* root) {
        if (!root) {
            return NodeValue(0, INT_MIN, INT_MAX); // Base case for null nodes
        }

        // Get values from left and right subtree (post-order traversal)
        auto lval = compute(root->left);
        auto rval = compute(root->right);

        // Check if the current node forms a BST
        if (root->data > lval.maxnode && root->data < rval.minnode) {
            // It is a BST, include this node
            return NodeValue(lval.size + rval.size + 1, 
                             max(root->data, rval.maxnode), 
                             min(root->data, lval.minnode));
        }

        // Otherwise, return invalid range [INT_MIN, INT_MAX] and max size
        return NodeValue(max(lval.size, rval.size), INT_MAX, INT_MIN);
    }

public:
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node* root) {
        return compute(root).size;
    }
};




//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends