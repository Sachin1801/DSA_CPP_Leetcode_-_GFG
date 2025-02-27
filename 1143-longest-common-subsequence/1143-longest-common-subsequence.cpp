class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        // dp[i][j] represents LCS length for text1[0...i-1] and text2[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};