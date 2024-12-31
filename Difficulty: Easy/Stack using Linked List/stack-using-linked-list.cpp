//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = NULL;
    }
};


// } Driver Code Ends
class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        if(top==NULL){
            top = new StackNode(x);
        }
        else{
            StackNode* n = new StackNode(x);
            StackNode* temp = top;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    int pop() {
        // code here
        if(top!=NULL)
        {
            int val;
            if(top->next==NULL){
                val = top->data;
                top = NULL;
                return val;
            }
            StackNode* temp = top;
            StackNode* prev = NULL;
            while(temp->next){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            return temp->data;
            
        }
        return -1;
    }

    MyStack() { top = NULL; }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        cout << "~"
             << "\n";
        delete sq;
    }
}

// } Driver Code Ends