//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
    
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    // dp[i][j] = max value using items up to i (0-based) with capacity j
    for(int i = 1; i <= n; i++){
        for(int cap = 0; cap <= capacity; cap++){
            // not take
            dp[i][cap] = dp[i-1][cap];
            // take (stay on i, i.e. i itself is not excluded in unbounded)
            if(wt[i-1] <= cap) {
                dp[i][cap] = max(dp[i][cap],
                                 val[i-1] + dp[i][cap - wt[i-1]]);
            }
        }
    }
    return dp[n][capacity];
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends