//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // Empty subset for sum = 0
        dp[0][0] = 1;
        
        // For each element
        for(int i = 1; i <= n; i++) {
            for(int sum = 0; sum <= target; sum++) {
                // Don't include current element
                dp[i][sum] = dp[i-1][sum];
                
                // Include current element if possible
                if(arr[i-1] <= sum) {
                    dp[i][sum] = (dp[i][sum] + dp[i-1][sum - arr[i-1]]) % MOD;
                }
            }
        }
        
        return dp[n][target];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends