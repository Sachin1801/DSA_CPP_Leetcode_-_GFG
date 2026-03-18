class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows= grid.size(), cols = grid[0].size();

        vector<int> prevColSum(cols, 0);
        int result = 0;

        for(int i = 0; i< rows; i++){
            // vector<int> currColSum = grid[i];
            int currSum = 0;
            for(int j =0; j< cols; j++){
                grid[i][j] += prevColSum[j];
                currSum += grid[i][j];
                if(currSum <= k) result++;

            }
            prevColSum = grid[i];
        }

        return result;
    }
};