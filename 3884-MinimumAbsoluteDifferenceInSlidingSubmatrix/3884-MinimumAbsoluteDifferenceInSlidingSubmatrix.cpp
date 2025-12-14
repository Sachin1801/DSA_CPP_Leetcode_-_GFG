// Last updated: 12/14/2025, 4:15:11 PM
class Solution {
private:
    int minimum_abs(vector<int>& v) {

        /* keep only distinct values and sort them
           O(t log t) with t ≤ k² ≤ 900, cheap      */
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (v.size() <= 1)
            return 0; // ← new: handle k = 1, or mono window

        int best = INT_MAX;
        for (size_t i = 1; i < v.size(); ++i) { // ← fixed loop condition
            best = min(best, v[i] - v[i - 1]);  // v is sorted → diff ≥ 0
        }
        return best;
    }

public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int outRows = m - k + 1;
        int outCols = n - k + 1;
        vector<vector<int>> ans(outRows, vector<int>(outCols));

        for (int top = 0; top + k <= m; top++) {
            for (int left = 0; left + k <= n; left++) {
                vector<int> val;
                val.reserve(k * k);
                for (int r = top; r < top + k; r++) {
                    for (int c = left; c < left + k; c++) {
                        val.push_back(grid[r][c]);
                    }
                }
                int min_abs = minimum_abs(val);
                ans[top][left] = min_abs;
            }
        }
        return ans;
    }
};