//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    string betterString(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        long long dp1[n+1], dp2[m+1];
        
        int lastOcc1[26], lastOcc2[26];
        
        for(int i = 0; i < 26; i++) {
            lastOcc1[i] = lastOcc2[i] = -1;
        }
        
        dp1[0] = dp2[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            dp1[i] = 2 * dp1[i-1];
            
            int lastIndex = lastOcc1[str1[i-1] - 'a'];
            if(lastIndex != -1) {
                dp1[i] = dp1[i] - dp1[lastIndex];
            }
            lastOcc1[str1[i-1] - 'a'] = i-1;
        }
        
        for(int i = 1; i <= m; i++) {
            dp2[i] = 2 * dp2[i-1];
            
            int lastIndex = lastOcc2[str2[i-1] - 'a'];
            if(lastIndex != -1) {
                dp2[i] = dp2[i] - dp2[lastIndex];
            }
            lastOcc2[str2[i-1] - 'a'] = i-1;
        }
        
        return (dp1[n] >= dp2[m]) ? str1 : str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends