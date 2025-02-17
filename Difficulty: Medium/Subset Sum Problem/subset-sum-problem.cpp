//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    private:
        
        bool check(int i, int sum, int k ,vector<int> &v){
    //base case
    if(sum==k) return true;
    if(i==v.size()) return false;

    //recvursive case
    if(sum + v[i] <=k){
        bool c1 = check(i+1,sum+v[i],k,v);
        if(c1) return true;
    }
    bool c2 = check(i+1,sum,k,v);
    return c2;
}
    
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        return check(0,0,target,arr);
        
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends