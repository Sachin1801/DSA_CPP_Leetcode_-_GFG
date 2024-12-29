//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int cnt = 0;
        int temp= n;
        while(temp&1){
            cnt++;
            temp = temp>>1;
        }
        int mask = 1<<cnt;
        return n | mask;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends