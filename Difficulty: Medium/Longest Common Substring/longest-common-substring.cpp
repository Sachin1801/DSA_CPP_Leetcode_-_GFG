//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code 
        int ss1 = s1.size();
        int ss2 = s2.size();
        if(ss1 ==0 || ss2==0) return 0;
        vector<vector<int>> dp(ss1+1,vector<int>(ss2+1,0));
        
        int ans = 0;
        for(int i=1;i<=ss1;i++){
            for(int j=1;j<=ss2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends