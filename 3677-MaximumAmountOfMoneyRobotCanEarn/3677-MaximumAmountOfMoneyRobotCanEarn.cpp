// Last updated: 12/14/2025, 4:15:23 PM
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = (int)coins.size();
        int n = (int)coins[0].size();

        // We will store dp[i][j][k] = maximum net coins after reaching (i,j)
        // having used k robber-neutralizations (k in [0..2]).
        // Initialize all to a very negative number (“-inf”) so that
        // we can take max() safely.
        static const int NEG_INF = -1000000000; 
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, NEG_INF))
        );

        // Initialize dp[0][0][...] depending on the cell (0,0).
        // If coins[0][0] >= 0, then no need to skip a robber.
        // If coins[0][0] < 0, we can either pay or skip (if we wish).
        int startVal = coins[0][0];
        if (startVal >= 0) {
            // Gains startVal coins, used 0 skips
            dp[0][0][0] = startVal;
            // Using a skip here doesn't make sense if startVal >= 0,
            // but we leave them as NEG_INF to indicate “unreachable”.
        } else {
            // If negative, we can pay the cost with 0 skips, or skip with up to 2 available.
            dp[0][0][0] = startVal;          // Did not skip
            dp[0][0][1] = 0;                 // Skip once
            // dp[0][0][2] could also be 0, but it’s enough to let dp[0][0][1] = 0
            // since using more than one skip on the same cell is pointless.
        }

        // Fill dp table
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    // If this state is unreachable, skip
                    if (dp[i][j][k] == NEG_INF) continue;

                    int currentCoins = dp[i][j][k];

                    // Move right
                    if (j + 1 < n) {
                        int valRight = coins[i][j + 1];
                        // 1) Not skipping (pay or gain valRight)
                        int &refNotSkip = dp[i][j + 1][k];
                        refNotSkip = max(refNotSkip, currentCoins + valRight);

                        // 2) Skip if valRight < 0 and we still have skip left
                        if (valRight < 0 && k < 2) {
                            int &refSkip = dp[i][j + 1][k + 1];
                            // Skipping means we add 0 instead of a negative cost
                            refSkip = max(refSkip, currentCoins + 0);
                        }
                    }

                    // Move down
                    if (i + 1 < m) {
                        int valDown = coins[i + 1][j];
                        // 1) Not skipping
                        int &refNotSkip = dp[i + 1][j][k];
                        refNotSkip = max(refNotSkip, currentCoins + valDown);

                        // 2) Skip if valDown < 0 and we still have skip left
                        if (valDown < 0 && k < 2) {
                            int &refSkip = dp[i + 1][j][k + 1];
                            refSkip = max(refSkip, currentCoins + 0);
                        }
                    }
                }
            }
        }

        // The answer is the best we can do among the 3 skip-counts
        int answer = max({ dp[m - 1][n - 1][0],
                           dp[m - 1][n - 1][1],
                           dp[m - 1][n - 1][2] });
        return answer;
    }
};