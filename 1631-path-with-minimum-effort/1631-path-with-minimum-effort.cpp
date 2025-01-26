class Solution {

private:
    bool check(int newrow, int newcol, int row, int col) {
        return (newrow < row and newrow >= 0 and newcol < col and newcol >= 0);
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rowsize = heights.size();
        int colsize = heights[0].size();
        pair<int, int> source = {0, 0};
        pair<int, int> destination = {rowsize - 1, colsize - 1};

        vector<vector<int>> distance(rowsize, vector<int>(colsize, INT_MAX));

        vector<pair<int, int>> directions = {
            {0, +1}, {0, -1}, {+1, 0}, {-1, 0}};
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        distance[0][0] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int currdist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == destination.first && col == destination.second)
                return currdist;
            for (auto p : directions) {
                int newrow = row + p.first;
                int newcol = col + p.second;
                if (check(newrow, newcol, rowsize, colsize)) {
                    int newEffort =
                        max(abs(heights[newrow][newcol] - heights[row][col]),
                            currdist);
                    if (newEffort < distance[newrow][newcol]) {
                        distance[newrow][newcol] = newEffort;
                        pq.push({distance[newrow][newcol], {newrow, newcol}});
                    }
                }
            }
        }
        return 0;
    }
};