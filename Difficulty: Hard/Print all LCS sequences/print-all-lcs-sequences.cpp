//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();

        // Step 1: Build the DP table where dp[i][j] = length of LCS of s[i..end], t[j..end].
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        // Memo structure: memo[i][j] will hold all distinct LCS (as strings) starting from s[i], t[j].
        vector<vector<set<string>>> memo(n + 1, vector<set<string>>(m + 1));

        // Step 2: Recursive function to retrieve all LCS of maximum length from (i, j).
        function<set<string>(int, int)> getAllLCS = [&](int i, int j) -> set<string> {
            // If we reach the end of either string, the only subsequence is the empty string.
            if (i == n || j == m) {
                return {""};
            }
            // If we already computed this state, just return it.
            if (!memo[i][j].empty()) {
                return memo[i][j];
            }

            // If characters match, prepend them to all subsequences from (i+1, j+1).
            if (s[i] == t[j]) {
                set<string> temp = getAllLCS(i + 1, j + 1);
                for (auto &sub : temp) {
                    memo[i][j].insert(s[i] + sub);
                }
            } else {
                // Move in the direction(s) that yield the LCS length.
                if (dp[i + 1][j] == dp[i][j]) {
                    set<string> down = getAllLCS(i + 1, j);
                    memo[i][j].insert(down.begin(), down.end());
                }
                if (dp[i][j + 1] == dp[i][j]) {
                    set<string> right = getAllLCS(i, j + 1);
                    memo[i][j].insert(right.begin(), right.end());
                }
            }
            return memo[i][j];
        };

        // Step 3: Get all LCSs starting from (0, 0). 
        // dp[0][0] is the length of the overall LCS for strings s and t.
        set<string> resultSet = getAllLCS(0, 0);

        // Convert the set to a vector (which is already in lexicographical order).
        vector<string> result(resultSet.begin(), resultSet.end());
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends