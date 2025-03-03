#define ll long long 

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<ll>> dp(n,vector<ll>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                }
                else if(j==n-1){
                    dp[i][j]=matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }else{
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
                }
            }
        }
        ll ans = INT_MAX;
        for(int j = 0;j<n;j++){
            ans = min(ans,dp[n-1][j]);
        }
        return (ll)ans;
    }
};