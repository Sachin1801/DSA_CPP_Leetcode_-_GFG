class Solution {
private:

    void compute(int start, int k, int rem, vector<int>& current,
                 vector<vector<int>>& ans) {
        if (current.size() == k) {
            if (rem == 0) {
                ans.push_back(current);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > rem)
                break;

            current.push_back(i);
            compute(i + 1, k, rem - i, current, ans);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        vector<vector<int>> ans;
        compute(1, k, n, current, ans);
        return ans;
    }
};