class Solution {
private:
    int ways(int rowSize, int colSize, int i, int j,vector<vector<int>>& og, vector<vector<int>> &dp ){
        //base case
        if(i >= rowSize || j >= colSize) return 0;
        if(og[i][j]==1) return dp[i][j]=0;
        if(i==rowSize-1 && j== colSize-1) return dp[i][j]= 1;

        //check if value if already computed
        if(dp[i][j]!= -1 ) return dp[i][j];

        //two ways
        //1. go downwards
        //2. go right 
        return dp[i][j]= ways(rowSize, colSize, i+1, j,og,dp) + ways(rowSize, colSize, i, j+1,og,dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int row = og.size();
        int col = og[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));

        return ways(row, col, 0, 0, og, dp);
    }
};