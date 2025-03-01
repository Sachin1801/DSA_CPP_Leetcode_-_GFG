//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

#define MOD 1000000007 

class Solution {
    private:
        vector<long long int> dp2;
  public:
  
  Solution(){
      dp2.resize(10001,-1);
  }
  
    long long int topDown(int n) {
        // code here
        if(n<=1){
            return n;
        }
        long long int dp[n+1]={0};
        dp[1]=1;
        for(long long int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        return dp[n];
    }
    long long int bottomUp(int n) {
        // code here
        if(n<=1) return dp2[n]=n;
        
        if(dp2[n]!=-1) return dp2[n];
        
        return dp2[n] =((bottomUp(n-1) + bottomUp(n-2))%MOD);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends