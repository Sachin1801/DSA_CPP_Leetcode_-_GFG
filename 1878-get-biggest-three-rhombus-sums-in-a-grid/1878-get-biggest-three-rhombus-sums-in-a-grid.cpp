class Solution {
    void insertSum(int val, set<int>& seen,
                   priority_queue<int, vector<int>, greater<int>>& heap) {
        if (seen.count(val)) return;
        if (heap.size() < 3) {
            seen.insert(val);
            heap.push(val);
        } else if (val > heap.top()) {
            seen.erase(heap.top());
            heap.pop();
            seen.insert(val);
            heap.push(val);
        }
    }

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        set<int> seen;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // area-0 rhombus (single cell) — always valid
                insertSum(grid[i][j], seen, minHeap);

                // max d such that all 4 corners fit in bounds
                int maxD = min({(n - 1 - i) / 2, j, m - 1 - j});

                for (int d = 1; d <= maxD; d++) {
                    int sum = 0;
                    for (int k = 0; k < d; k++) {
                        sum += grid[i + k][j + k];
                        sum += grid[i + d + k][j + d - k];
                        sum += grid[i + 2*d - k][j - k];
                        sum += grid[i + d - k][j - d + k];
                    }
                    insertSum(sum, seen, minHeap);
                }
            }
        }

        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};