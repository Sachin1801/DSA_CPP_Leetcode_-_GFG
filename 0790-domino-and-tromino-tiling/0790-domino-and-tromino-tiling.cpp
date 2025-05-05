class Solution {
private:
    int dp[1005][1005];
    int MOD = 1e9+7;
    int countTilingWays(int r1, int r2){
        if(r1==0 && r2==0) return 1;
        if(r1 < 0 || r2 < 0) return 0; //invalid tiling
        if(dp[r1][r2]!=-1) return dp[r1][r2];

        long long count = 0;
        if(r1==r2){
            count += countTilingWays(r1-2,r2-2);      // Horizontally tile row-1 & row-2
            // Vertically tile row-1 and row-2
            count += countTilingWays(r1-1,r2-1);
            //Inverted L shape
            count += countTilingWays(r1-2,r2-1);
            // Mirrow L shape
            count+= countTilingWays(r1-1,r2-2);
        }else if(r1 > r2){
            //inverted L-Mirror shapr
            count+= countTilingWays(r1-2, r2-1);

            //horizontal tile on row-1
            count += countTilingWays(r1-2, r2);
        }else{
            //L-shape
            count+= countTilingWays(r1-1,r2-2);
            //Horizontal tile on row-2
            count+= countTilingWays(r1,r2-2);
        }
        return dp[r1][r2]= count%MOD;
    }

public:
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return countTilingWays(n,n);
    }
};