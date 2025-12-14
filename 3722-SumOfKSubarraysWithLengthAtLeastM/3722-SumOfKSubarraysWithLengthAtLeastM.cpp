// Last updated: 12/14/2025, 4:15:19 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int M) {
        int n = (int)nums.size();
        vector<long long> pref(n + 1, 0LL);
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i - 1] + nums[i - 1];
        }

        // dp[i][j] = max total sum using j subarrays in first i elements
        // bst[j][i] = max of (dp[x][j] - pref[x]) for x in [0..i]
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, LLONG_MIN));
        vector<vector<long long>> bst(k + 1, vector<long long>(n + 1, LLONG_MIN));

        dp[0][0] = 0LL;
        bst[0][0] = -pref[0];

        for(int i = 1; i <= n; i++){
            dp[i][0] = 0LL;
            long long cand = (dp[i][0] == LLONG_MIN ? LLONG_MIN : dp[i][0] - pref[i]);
            bst[0][i] = max(bst[0][i - 1], cand);
        }

        for(int j = 1; j <= k; j++){
            for(int i = 1; i <= n; i++){
                dp[i][j] = dp[i - 1][j];
                if(i >= M && bst[j - 1][i - M] != LLONG_MIN){
                    long long x = pref[i] + bst[j - 1][i - M];
                    dp[i][j] = max(dp[i][j], x);
                }
                if(dp[i][j] == LLONG_MIN){
                    bst[j][i] = bst[j][i - 1];
                } else {
                    long long cand = dp[i][j] - pref[i];
                    bst[j][i] = max(bst[j][i - 1], cand);
                }
            }
        }

        return (dp[n][k] == LLONG_MIN ? 0LL : dp[n][k]);
    }
};
