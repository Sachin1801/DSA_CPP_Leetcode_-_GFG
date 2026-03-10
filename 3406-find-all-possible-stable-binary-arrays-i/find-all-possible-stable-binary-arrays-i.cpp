// #define MOD 1e9+7;

class Solution {
public:
    int dp[201][201][2];
    int MOD = 1e9 + 7;

    int solve(int zeroLeft, int onesLeft, int limit, bool lastWasOne){
        if(zeroLeft == 0 && onesLeft == 0 ){
            return 1;
        }
        int ans = 0;

        if(dp[zeroLeft][onesLeft][lastWasOne]!= -1) return dp[zeroLeft][onesLeft][lastWasOne];

        // add 0 when flp = false || add 0 by default
        if(lastWasOne){
            // explore 0
            for(int i =1; i <=min(limit, zeroLeft); i++){
                ans = (ans +  solve(zeroLeft - i, onesLeft, limit, false)) % MOD ;
            }
        }else{
            // explore 1
            for(int i =1; i<= min(limit, onesLeft) ; i++){
                ans = (ans +  solve(zeroLeft, onesLeft - i, limit, true)) % MOD ;
            }
        }
        return dp[zeroLeft][onesLeft][lastWasOne] = ans;

    }

    int numberOfStableArrays(int zero, int one, int limit) {
        
        memset(dp, -1, sizeof(dp));

        return (solve(zero, one, limit, true) + solve(zero, one, limit, false)) % MOD;
    }
};