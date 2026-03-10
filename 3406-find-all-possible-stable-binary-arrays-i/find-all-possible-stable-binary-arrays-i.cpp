// #define MOD 1e9+7;

class Solution {
public:
    int dp[201][201][2];
    int MOD = 1e9 + 7;

    // int solve(int zeroLeft, int onesLeft, int limit, bool lastWasOne){
    //     if(zeroLeft == 0 && onesLeft == 0 ){
    //         return 1;
    //     }
    //     int ans = 0;

    //     if(dp[zeroLeft][onesLeft][lastWasOne]!= -1) return dp[zeroLeft][onesLeft][lastWasOne];

    //     // add 0 when flp = false || add 0 by default
    //     if(lastWasOne){
    //         // explore 0
    //         for(int i =1; i <=min(limit, zeroLeft); i++){
    //             ans = (ans +  solve(zeroLeft - i, onesLeft, limit, false)) % MOD ;
    //         }
    //     }else{
    //         // explore 1
    //         for(int i =1; i<= min(limit, onesLeft) ; i++){
    //             ans = (ans +  solve(zeroLeft, onesLeft - i, limit, true)) % MOD ;
    //         }
    //     }
    //     return dp[zeroLeft][onesLeft][lastWasOne] = ans;

    // }

    int numberOfStableArrays(int zero, int one, int limit) {
        
        memset(dp, 0, sizeof(dp));
        dp[0][0][1] = 1;
        dp[0][0][0] =1;

        for(int onesLeft = 0 ; onesLeft <= one; onesLeft++){
            for(int zeroLeft = 0; zeroLeft <= zero; zeroLeft++){
                if(onesLeft == 0 && zeroLeft == 0){
                    continue;
                }

                int result = 0;

                // if(lastWasone == true ) -> explore 0s
                result = 0;
                for(int len = 1; len <= min(limit, zeroLeft); len++){
                    result = (result + dp[zeroLeft - len][onesLeft][0]) % MOD;
                }
                dp[zeroLeft][onesLeft][1] = result;
                
                result = 0;
                for(int len = 1; len <= min(limit, onesLeft); len++){
                    result = (result + dp[zeroLeft][onesLeft - len][1]) % MOD;
                }
                dp[zeroLeft][onesLeft][0] = result ;
            }
        }

        return (dp[zero][one][1] + dp[zero][one][0]) % MOD;
    }
};