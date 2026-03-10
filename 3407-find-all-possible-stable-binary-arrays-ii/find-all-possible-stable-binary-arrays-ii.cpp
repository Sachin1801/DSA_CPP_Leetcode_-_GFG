class Solution {
public:

    int numberOfStableArrays(int zero, int one, int limit) {

       int M = 1e9 + 7; 
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one+1, vector<int>(2,0)));
        // dp[0][0][1] = 1;
        // dp[0][0][0] =1;

        for(int i =0; i<= min(zero, limit); i++){
            dp[i][0][0] = 1;
        }

        for(int j = 0; j <= min(one, limit); j++){
            dp[0][j][1] = 1;
        }

        for(int i = 0 ; i <= zero; i++){
            for(int j = 0; j <= one; j++){
                if(i == 0 || j == 0){
                    continue;
                }

                // int result = 0;

                // if(lastWasone == true ) -> explore 0s
                if(j>0){
                    dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % M;
                    if(j-1 >= limit){
                        dp[i][j][1] = (dp[i][j][1] - dp[i][j-1-limit][0] + M ) % M;
                    }
                }

                if(i>0){
                    dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % M;
                    if(i-1 >= limit){
                        dp[i][j][0] = (dp[i][j][0] - dp[i-1-limit][j][1] + M ) % M ;
                    }
                }
            }
        }

        return (dp[zero][one][1] + dp[zero][one][0]) % M;
    }
};