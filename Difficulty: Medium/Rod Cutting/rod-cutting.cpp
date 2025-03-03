//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        int f(int i, int cap, vector<int>& price, vector<vector<int>> &dp){
            if(i==0){
                return dp[i][cap] = cap*price[0];
            }
            
            if(dp[i][cap]!=-1) return dp[i][cap];
            
            int notTake= 0 + f(i-1,cap,price,dp);
            
            int take = INT_MIN;
            int rodlength = i+1;
            if(rodlength <=cap)
                take = price[i]+f(i,cap-rodlength,price,dp);
            return dp[i][cap] = max(take,notTake);
        }
    
  public:
    int cutRod(vector<int> &price) {
        // code here
        int cap = price.size();
        vector<vector<int>> dp(cap,vector<int>(cap+1,-1));
        return f(cap-1,cap,price,dp);
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