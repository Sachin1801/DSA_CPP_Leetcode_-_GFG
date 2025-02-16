class Solution {
private:
    bool backtrack(int i, vector<int>& ans, vector<int> &marked, int n) {
        if (i == ans.size())
            return true;

        if (ans[i] != 0)
            return backtrack(i + 1, ans, marked, n);

        for (int j = n; j > 0; j--) {
            // Validation check
            if (marked[j]) continue;

            if (j > 1 && (i + j >= ans.size() || ans[i + j] != 0))
                continue;

            // Try placing j
            marked[j] = 1;
            ans[i] = j;
            if (j > 1) ans[i + j] = j;

            // Recursive step
            if (backtrack(i + 1, ans, marked, n))
                return true;

            // Backtrack
            marked[j] = 0;
            ans[i] = 0;
            if (j > 1) ans[i + j] = 0;
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);
        vector<int> marked(n + 1, 0); // Replace unordered_set with a vector
        backtrack(0, ans, marked, n);
        return ans;
    }
};
