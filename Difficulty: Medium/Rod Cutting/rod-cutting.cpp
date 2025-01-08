//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        int *dp= new int[n+1]();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]=max(dp[i],dp[j-1]+price[i-j]);
            }
        }
        int result = dp[n];
        delete[] dp;
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends