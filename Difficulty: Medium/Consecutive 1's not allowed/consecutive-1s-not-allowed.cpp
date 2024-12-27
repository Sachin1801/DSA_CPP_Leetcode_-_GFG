//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // #define ll long long
    int countStrings(int n) {
        // code here
        int zeroend = 1;
        int oneend = 1;
        int sum = zeroend + oneend;
        if(n==1) return sum;
        int i=2;
        while(i<=n){
            oneend = zeroend;
            zeroend = sum ;
            sum = oneend + zeroend;
            i++;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.countStrings(n);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends