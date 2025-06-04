class Solution {
private:
    int dfs(int box, vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
            unordered_set<int>& visited, unordered_set<int>& foundBoxes) {
        if (visited.count(box)) {
            return 0;
        }

        // if we cannot open the open the box because of closed status
        if (status[box] == 0) {
            foundBoxes.insert(box);
            return 0;
        }
        int candiesCollected = candies[box];
        visited.insert(box);

        for (int& insideBox : containedBoxes[box]) {
            candiesCollected += dfs(insideBox, status, candies, keys,
                                    containedBoxes, visited, foundBoxes);
        }

        for (int& boxKey : keys[box]) {
            status[boxKey] = 1; // can be opened
            candiesCollected += dfs(boxKey, status, candies, keys,
                                    containedBoxes, visited, foundBoxes);
        }
        return candiesCollected;
    }

public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        if (initialBoxes.size() == 0)
            return 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;

        int candy = 0;

        for (int& boxes : initialBoxes) {
            candy += dfs(boxes, status, candies, keys, containedBoxes,
                           visited, foundBoxes);
        }

        return candy;
    }
};