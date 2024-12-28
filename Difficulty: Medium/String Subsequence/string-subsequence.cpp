//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int MOD = 1e9 + 7;
    
    int countWays(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        // dp[i][j] represents count of subsequences of s1[0..i] equal to s2[0..j]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Empty string is subsequence of empty string
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        // For each position in s1 and s2
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j];  // Don't take current char
                
                // If characters match, add subsequences including current char
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                }
            }
        }
        
        return dp[n][m];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends