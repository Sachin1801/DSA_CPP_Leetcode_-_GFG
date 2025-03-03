class Solution {
private:
    int ways(int row, int col, int r, int c, vector<vector<int>> &dp){
        if(r >= row || c >= col) return 0;
        if(r == row-1 && c== col-1) return dp[r][c] = 1;

        //if value alredy present
        if(dp[r][c]!=-1) return dp[r][c];

        //two ways
        //1. down i.e r +1
        //2. right i.e c+1

        return dp[r][c] = ways(row,col,r+1,c,dp) + ways(row,col,r,c+1,dp);
    }

public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m,vector<int>(n,-1));
        return ways(m,n,0,0,dp);
    }
};