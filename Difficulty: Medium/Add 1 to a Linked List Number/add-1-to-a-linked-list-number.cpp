//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++
/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
private:
    Node* reverse(Node* head) {
        Node *prev = NULL, *curr = head, *next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(head==NULL) return head;
        head = reverse(head);
        int carry = 1;
        Node* curr = head;
        while(curr && carry){
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum/ 10;
            
            //if carry = 1 and curr is on the last node
            if(carry and curr->next==NULL){
                curr->next = new Node(carry);
                break;
            }
            curr = curr->next;
        }
        head = reverse(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends