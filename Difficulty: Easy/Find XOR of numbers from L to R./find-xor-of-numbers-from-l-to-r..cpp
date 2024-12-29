//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    int calcxor(int n){
        if(n%4==1)
            return 1;
        else if(n%4==2)
            return n+1;
        else if(n%4==3)
            return 0;
        else
            return n;
    }
    
  public:
    int findXOR(int l, int r) {
        // complete the function here
        int lxor = calcxor(l-1);
        int rxor = calcxor(r);
        return rxor ^ lxor;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends