// Last updated: 12/14/2025, 4:15:16 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
    string s;
    vector<vector<vector<int>>> dp;

    int shiftCost(char a, char b){
        int d = abs(a - b);
        return min(d, 26 - d);
    }

    int solve(int i, int j, int k){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j][k] != -1) return dp[i][j][k];

        int ans = max(solve(i+1, j, k), solve(i, j-1, k));
        int cost = shiftCost(s[i], s[j]);
        if(cost <= k) ans = max(ans, 2 + solve(i+1, j-1, k - cost));

        dp[i][j][k] = ans;
        return ans;
    }

public:
    int longestPalindromicSubsequence(string s_, int K) {
        s = s_;
        int n = (int)s.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(K + 1, -1)));
        return solve(0, n - 1, K);
    }
};
