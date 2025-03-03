class Solution {
    int ways(int row, int idx,int sz, vector<vector<int>> &dp, vector<vector<int>> &triangle){
        if(row>=sz || idx >=sz) return 0;
        if(row==sz-1){
            cout<<triangle[row][idx]<<" ";
            return dp[row][idx]= triangle[row][idx];
        } 

        //if value already present
        if(dp[row][idx]!=-1) return dp[row][idx];

        int left =0;
        if(row + 1 < sz)
            left = ways(row+1,idx,sz,dp,triangle);
        int right = 0;
        if(row + 1 < sz && idx + 1 < sz)
            right = ways(row+1,idx+1,sz,dp,triangle);

        return dp[row][idx] = min(left,right) + triangle[row][idx];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int maxrow = triangle.size();
        vector<vector<int>> dp(maxrow, vector<int>(maxrow,-1));
        if(maxrow==1) return triangle[0][0];
        return ways(0,0,maxrow,dp, triangle);

        
    }
};