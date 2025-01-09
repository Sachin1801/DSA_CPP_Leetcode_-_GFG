//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // Initialize dp array.
        vector<int> dp(sum + 1, INT_MAX);

        // Base case: 0 coins are needed to make sum 0.
        dp[0] = 0;

        // Iterate over each coin.
        for (int coin : coins) {
            for (int j = coin; j <= sum; j++) {
                if (dp[j - coin] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coin] + 1);
                }
            }
        }

        // If dp[sum] is still INT_MAX, the sum is not achievable.
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends