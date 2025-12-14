// Last updated: 12/14/2025, 4:15:12 PM
#include <bits/stdc++.h>
using namespace std;

namespace {
int transformCost(const string& a, const string& b) {
    int freq[26][26] = {};
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] != b[i])
            ++freq[a[i] - 'a'][b[i] - 'a'];
    int swaps = 0;
    for (int x = 0; x < 26; ++x)
        for (int y = x + 1; y < 26; ++y) {
            int t = min(freq[x][y], freq[y][x]);
            swaps += t;
            freq[x][y] -= t;
            freq[y][x] -= t;
        }
    int repl = 0;
    for (int x = 0; x < 26; ++x)
        for (int y = 0; y < 26; ++y)
            if (x != y) repl += freq[x][y];
    return swaps + repl;
}

int blockCost(string a, const string& b) {
    if (a == b) return 0;
    int keep = transformCost(a, b);
    reverse(a.begin(), a.end());
    return min(keep, 1 + transformCost(a, b));
}
}

class Solution {
public:
    int minOperations(string w1, string w2) {
        int n = w1.size(), inf = 1e9;
        vector<vector<int>> cost(n, vector<int>(n));
        for (int l = 0; l < n; ++l) {
            string a, b;
            for (int r = l; r < n; ++r) {
                a.push_back(w1[r]);
                b.push_back(w2[r]);
                cost[l][r] = blockCost(a, b);
            }
        }
        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                dp[i] = min(dp[i], dp[j] + cost[j][i - 1]);
        return dp[n];
    }
};
