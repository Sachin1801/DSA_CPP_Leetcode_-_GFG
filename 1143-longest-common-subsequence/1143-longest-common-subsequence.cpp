class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ts1 = text1.length();
        int ts2 = text2.length();

        vector<vector<int>> dp(ts1+1,vector<int>(ts2+1,-1));
        //pre-computation
        for(int i=0;i<=ts1;i++){
            dp[i][0]=0;            
        }
        for(int i=1;i<=ts2;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<=ts1;i++){
            for(int j=1; j<=ts2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[ts1][ts2];
    }
};