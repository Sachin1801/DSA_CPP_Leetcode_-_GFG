class Solution {
public:
    int countSq(vector<vector<int>> &matrix, int n, int m){
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0) cnt+= matrix[i][j];
            }
        }
        return cnt;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int cnt = 0;
        if(n==1 || m==1 ){
            cnt = countSq(matrix,n,m);
            return cnt;
        }

        // initialise the dp vector
        // same dimensions as the matrix
        vector<vector<int>> dp(n,vector<int>(m,0)); //store how many square matrices right bottom end here

        //replicate the first row and the first column
        // they remain unchanged
            //if 1 : only contribute once
            //if 0 : cannot contribute
        for(int i=0;i<n;i++) dp[i][0] =  matrix[i][0]; 
        for(int i =0;i<m;i++) dp[0][i] = matrix[0][i];

        for(int i=1; i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0) dp[i][j]=0;
                else{
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }

        cnt = countSq(dp,n,m);
        return cnt;
    }
};